/*

  Project:       1Sheeld Library 
  File:          GraphShield.cpp
                 
  Version:       1.12.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.12

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GraphShield.h"



GraphShield::GraphShield() : ShieldParent(GRAPH_ID)
{
	for(int i=0;i<5;i++){
		namesArray[i]=NULL;
		floatArray[i]=0;
		chartIDArray[i]=0;
	}
	keysCounter= 0 ;
}

void GraphShield::add(const char * _key,float _value, byte _chartID)
{
	byte keyLength=strlen(_key);
	if(!keyLength||keysCounter >= 5) return;	
	
	byte found = false;
	if(_chartID>=5)
	{
		_chartID=4;
	}
	
	for(int i=0 ;i<keysCounter;i++)
	{
		if(!strcmp(namesArray[i],_key) && chartIDArray[i]==_chartID)
		{
			floatArray[i]=_value;
			found=true;
		}
	}

	if(!found)
	{
		
		key = (char*)malloc(sizeof(char)*(keyLength+1));
		for (int j=0; j<keyLength; j++)
		{
			key[j]=_key[j];
		}
		key[keyLength]='\0';
		namesArray[keysCounter]=key;
		floatArray[keysCounter]=_value;
		chartIDArray[keysCounter]=_chartID;
		keysCounter++;
	}
}

void GraphShield::plot()
{
	if(keysCounter>0)
	{
		FunctionArg **arguments =(FunctionArg**)malloc(sizeof(FunctionArg *)*(keysCounter*3));
		byte stepCounter =0;
	  	for(int i=0 ;i<keysCounter*3;i+=3)
	  	{
	  		arguments[i]=   new FunctionArg(strlen(namesArray[stepCounter]),(byte*)(namesArray[stepCounter]));
	  		arguments[i+1]= new FunctionArg(4,(byte*)OneSheeld.convertFloatToBytes(floatArray[stepCounter]),true);
	  		arguments[i+2]= new FunctionArg(1,&chartIDArray[stepCounter]);
	  		stepCounter++;
	  	}
		OneSheeld.sendShieldFrame(GRAPH_ID,0,GRAPH_PLOT,keysCounter*3,arguments);
	    
	    for(int i=0;i<keysCounter*3;i++)
	    {
	      delete arguments[i];
	    }
		free(arguments);
		for(int i=0 ;i<keysCounter;i++)
		{
			if(namesArray[i]!=0)
			{
				free(namesArray[i]);
				namesArray[i]=NULL;
				floatArray[i]=0;
				chartIDArray[i]=0;
			}
		}
		keysCounter=0;
	}
}

void GraphShield::saveCsv(const char * fileName,byte _chartID, byte _saveType)
{
	if(_chartID <5)
	{
		OneSheeld.sendShieldFrame(GRAPH_ID,0,GRAPH_SAVE_CSV,3,new FunctionArg(strlen(fileName),(byte*)fileName),new FunctionArg(1,&_chartID),new FunctionArg(1,&_saveType));
	}
}

void GraphShield::saveScreenShot(byte _chartID)
{
	OneSheeld.sendShieldFrame(GRAPH_ID,0,GRAPH_SAVE_SCREENSHOT,1,new FunctionArg(1,&_chartID));
}

void GraphShield::clear(byte _chartID)
{
	if(_chartID <5)
	{
		OneSheeld.sendShieldFrame(GRAPH_ID,0,GRAPH_CLEAR,1,new FunctionArg(1,&_chartID));
	}
}

void GraphShield::autoScroll(byte state)
{
	OneSheeld.sendShieldFrame(GRAPH_ID,0,GRAPH_AUTO_SCROLL,1,new FunctionArg(1,&state));
}