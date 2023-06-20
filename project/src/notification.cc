#include <iostream>
#include <string>

#include "notification.h"

Notification::Notification(){
	battery = 0;
	damaged = 0;
	severeWeather = 0;
}

Notification::Notification(int batteryLife, int isDamaged, int isSevereWeather) {
	battery = batteryLife;
	damaged = isDamaged;
	severeWeather = isSevereWeather;
}

Notification::~Notification() {
	delete
}

Notification::getBattery() {
	return this->battery;
}
Notification::getDamaged() {
	return this->damaged;
}
Notification::getSevereWeather() {
	return this->severeWeather;
}

Notification::displayBattery() {
	if (this->battery <= 20) {
		return cout<<"Low battery"<<endl;
	}
	else {
		return;
	}
}

Notification::displayDamaged() {
	if (this->damaged == 1) {
		return cout<<"The drone has been damaged!"<<endl;
	}
	else {
		return;
	}
}

Notification::displaySevereWeather() {
	if (this->severeWeather == 1) {
		return cout<<"There is a storm ahead!"<<endl;
	}

	if (this->severeWeather == 2) {
		return cout<<"There is a tornado ahead!"<<endl;
	}

	if (this->severeWeather == 3) {
		return cout<<"There is flooding ahead!"<<endl;
	}

	if (this->severeWeather == 4) {
		return cout<<"There is snow ahead!"<<endl;
	}
}