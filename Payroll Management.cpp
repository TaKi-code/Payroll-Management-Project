#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace chrono;
using namespace this_thread;

class Account {
public :
	char name[12], surname[12];
	int age;
	void Change_Salary(int a) { salary = a; }
	void Change_Username(char a[12]) { strcpy_s(username, a); }
	void Change_Password(char a[12]) { strcpy_s(password, a); }
	int Ret_Salary() { return salary; }
	char* Ret_Username() { return username; }
	char* Ret_Password() { return password; }
private :
	int salary;
	char username[12], password[12];
};

Account account[100];

ifstream fin("TextFile4.txt");

int cont;

void Citire_Date_Initial() {
	fin >> cont;
	for (int i = 1; i <= cont; i++) {
		fin >> account[i].name >> account[i].surname >> account[i].age;
		char citire_user[12], citire_pass[12];
		int sal;
		fin >> citire_user >> citire_pass >> sal;
		account[i].Change_Username(citire_user); 
		account[i].Change_Password(citire_pass);
		account[i].Change_Salary(sal);
	}
}

void Case4(int k, int& aux) {
	system("CLS");
	cout << "Are you sure you want to exit ? (Y/N) : "; char option_Case4; cin >> option_Case4;
	switch (option_Case4) {
	case 'Y':
		cout << " OKEY :( ";
		aux = 1;
	case 'N':
		cout << "SUPER";
		aux = 0;
	}
}

void Case3(int k) {
	system("CLS");
	cout << " Your salary is " << account[k].Ret_Salary(); sleep_for(milliseconds(50));
	cout << "\nWould you like to request a payslip ? (Y/N) : "; char option_Case3; cin >> option_Case3;
	switch (option_Case3) {
	case 'Y':
		cout << "OKeey done ";
		sleep_for(seconds(1));
	case 'N':
		cout << "No pronlem ";
		sleep_for(seconds(1));
	}
}

void delete_account(int k) {
	for (int i = k + 1; i <= cont; i++) {
		strcpy_s(account[i - 1].name, account[i].name);
		strcpy_s(account[i - 1].surname, account[i].surname);
		account[i - 1].age = account[i].age;
		account[i - 1].Change_Username(account[i].Ret_Username());
		account[i - 1].Change_Password(account[i].Ret_Password());
		account[i - 1].Change_Salary(account[i].Ret_Salary());
	}
	cont--;
}

void Case2(int k, int& retine) {
	system("CLS");
	cout << "\n\n Are you sure that you want to delete your account ? (Y/N) "; char option_Case2; cin >> option_Case2;
	switch (option_Case2) {
	case 'Y':
		cout << "okeey :( "; sleep_for(milliseconds(50));
		delete_account(k);
		cout << "\nAccount DELTED ... you will be taken back to login ";
		sleep_for(seconds(1));
		retine = 0;
	case 'N':
		cout << "\nGlad to hear that :)";
		sleep_for(milliseconds(50));
		retine = 1;
	}
}

void Case15(int k) {
	cout << "\n\n Please enter your new Password : "; char new_Password[12]; cin >> new_Password;
	sleep_for(milliseconds(50)); account[k].Change_Password(new_Password);
	cout << "\n Password actualised ... in 1 seeconds you will be taken back ! "; sleep_for(seconds(1));
}

void Case14(int k) {
	cout << "\n\n Please enter your new Username : "; char new_Username[12]; cin >> new_Username;
	sleep_for(milliseconds(50)); account[k].Change_Username(new_Username);
	cout << "\n Username actualised ... in 1 seeconds you will be taken back ! "; sleep_for(seconds(1));
}

void Case13(int k) {
	cout << "\n\n Please enter your new age : "; int new_age; cin >> new_age;
	sleep_for(milliseconds(50)); account[k].age = new_age;
	cout << "\n Age actualised ... in 1 seeconds you will be taken back ! "; sleep_for(seconds(1));
}

void Case12(int k) {
	cout << "\n\n Please enter your new Surname : "; char new_Surname[12]; cin >> new_Surname;
	sleep_for(milliseconds(50)); strcpy_s(account[k].surname, new_Surname);
	cout << "\n Surname actualised ... in 1 seeconds you will be taken back ! "; sleep_for(seconds(1));
}

void Case11(int k) {
	cout << "\n\n Please enter your new Name : "; char new_Name[12]; cin >> new_Name;
	sleep_for(milliseconds(50)); strcpy_s(account[k].name, new_Name);
	cout << "\n Name actualised ... in 1 seconds you will be taken back ! "; sleep_for(seconds(1));
}

int verif_exist_user(char a[12]) {
	for (int i = 1; i <= cont; i++)
		if (strcmp(a, account[i].Ret_Username()) == 0)
			return i;
	return 0;
}

bool verif_corr_pass(int k, char a[]) {
	if (strcmp(account[k].Ret_Password(), a) == 1)
		return true;
	return false;
}

void Case1(int k) {
	system("CLS");
	int k_aux = k;
	cout << "What would you like to edit ? ";
	cout << "\n1.Name\n2.Surname\n3.age\n4.username\n5.password\n6.Back to Menu";
	cout << "\n\nChoose your option (1-6) : "; int new_option; cin >> new_option;
	switch (new_option) {
	case 1:
		Case11(k_aux);
		Case1(k_aux);
	case 2:
		Case12(k_aux);
		Case1(k_aux);
	case 3:
		Case13(k_aux);
		Case1(k_aux);
	case 4:
		Case14(k_aux);
		Case1(k_aux);
	case 5:
		Case15(k_aux);
		Case1(k_aux);
	case 6:
		cout << "\n\n Are you sure you don`t want to change anything else ? (Y/N)  : "; char option_case16; cin >> option_case16;
		switch (option_case16) {
		case 'Y':
			cout << "\nOKEY";
			sleep_for(milliseconds(50));
		case 'N':
			cout << "\n Good Choice :) ";
			Case1(k_aux);
		}
	}
}

void Next_Main_Menu(int k) {
	system("CLS");
	int k_aux = k;
	cout << "   MAIN MENU ";
	cout << "\n1.Edit\n2.Delete\n3.Payslip\n4.Exit\n\nChoose option(1-4) : ";
	int option; cin >> option;
	switch (option) {
	case 1:
		Case1(k_aux);
		Next_Main_Menu(k_aux);
	case 2:
		int retine;
		Case2(k_aux, retine);
		if (retine == 1)
			Next_Main_Menu(k_aux);
	case 3:
		Case3(k_aux);
		Next_Main_Menu(k_aux);
	case 4:
		int aux_retine;
		Case4(k_aux, aux_retine);
		if (aux_retine == 1)
			return;
		else
			Next_Main_Menu(k_aux);
	}
}

void Main_Menu() {
	system("CLS");
	cout << "         Welcome ";
	cout << "\n\nPlease Login : \n\nUsername : "; char intr_user[12]; cin >> intr_user;
	if (verif_exist_user(intr_user) == 0) {
		cout << "\n Username Doesn`t exist ... Please wait a second a try again ";
		sleep_for(seconds(1));
		Main_Menu();
	}
	else {
		cout << "\nUsername gasit "; sleep_for(milliseconds(30));
		cout << "\nIntroduceti parola pentru username : " << intr_user << "  : "; char intr_pass[12]; cin >> intr_pass;
		if (verif_corr_pass(verif_exist_user(intr_user), intr_pass) == false) {
			cout << "\n Incorrect Password ... Please wait a second and try again "; sleep_for(seconds(1));
			Main_Menu();
		}
		else {
			cout << "\nCorrect Password ... wait one seconds to Login "; sleep_for(milliseconds(50));
			int k = verif_exist_user(intr_user);
			Next_Main_Menu(k);
		}
	}
}

int main() {
	Citire_Date_Initial();
	Main_Menu();
	return 0;
}