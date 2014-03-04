#ifndef PressureSensorShield_h
#define PressureSensorShield_h

#define PRESSURE_VALUE 0x01

class PressureSensorShield
{
public:
	PressureSensorShield();
	unsigned long getValue();
private:
	void processData();
	unsigned long value;
	 long data[2];
	 friend class OneSheeldClass;

};

extern PressureSensorShield PressureSensor;
#endif  