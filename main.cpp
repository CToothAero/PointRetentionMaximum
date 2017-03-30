#include <iostream>
#include <string>

const double tolerance = .0001;

double getRetentionRate(void);
double getStartingValue(void);
void calculateMaximumValue(double start, double retention, int& counter);
void clearScreen(void);

int main (void){
	int stepCounter = 0;

	calculateMaximumValue(getStartingValue(),getRetentionRate(), stepCounter);

	system("PAUSE");
	return 0;
}

double getRetentionRate(void){
	double temp = 0.0;
	clearScreen();

	while (true){
		printf("Enter Retention Rate (as decimal): ");
		std::cin >> temp;

		if ((temp < 0.0)||(temp > 1.0)){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			return temp;
		}
	}
}

double getStartingValue(void){
	double temp = 0.0;
	while (true){
		printf("Enter Starting Value: ");
		std::cin >> temp;
		if (temp < 0.0){
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		} else {
			return temp;
		}
	}
}

void calculateMaximumValue(double start, double retention, int& counter){
	double newValue = start;
	double oldValue = 0.0;
	double totalLost = 0.0;

	printf("Rounds\tOld\tNew\tTotalLost\n");
	while ((newValue - oldValue) > tolerance){
		counter++;
		oldValue = newValue;
		newValue = start + retention*oldValue;
		newValue = floor(newValue);
		totalLost = ((start*(counter+1))-newValue);
		printf("%i\t%.0f\t%.0f\t%.0f\n",counter,oldValue,newValue,totalLost);
	}
}

void clearScreen(void){
	printf("%s",std::string(25,'\n').c_str());
}