#include<iostream>
using namespace std;

bool IsLeapYear(int Year) {

	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

int DayOfWeekOrder(int Year, int Month, int Day) {

	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(int DayOfWeekOrder) {

	string arrDayNames[] = { "Sun","Mon","Tues","Wed","Thusr","Fri","Satur" };

	return arrDayNames[DayOfWeekOrder];

}

int NumberOfDaysInMonth(int Month, int Year) {

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

string MonthShortName(int Month) {

	string arrMonthName[12] = { "Jounewary","Febrawary","Mars","April","May","Jouin","Jolai",
		"Augest","September","October","Novermber","Desamber" };
	return arrMonthName[Month - 1];

}

void PrintMonthCalender(int Month, int Year) {




	int Current = DayOfWeekOrder(1, Month, Year);

	int NumberOfDays = NumberOfDaysInMonth(Month, Year);

	printf("\n_________________%s________________\n\n", MonthShortName(Month).c_str());

	printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i = 0;
	for (i = 0; i < Current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++) {

		printf("%5d", j);

		if (++i == 7) {

			i = 0;
			printf("\n");
		}
	}

	printf("\n__________________________________________\n");
}

int ReadYearNumber() {


	int Year;

	cout << "enter please nuumber the year: ";
	cin >> Year;

	while (Year <= 0) {
		cout << "\nerorr..., enter please agin: ";
		cin >> Year;
	}
	return Year;
}


void PrintYearCalender(int Year) {


	cout << "\n\n           Calender - " << Year << "\n\n";

	for (int i = 1; i <= 12; i++) {

		PrintMonthCalender(i, Year);

	}

}

int main() {


	PrintYearCalender(ReadYearNumber());

	return 0;


}