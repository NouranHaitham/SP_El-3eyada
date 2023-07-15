#pragma once

#include<stdio.h>
#include<conio.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
#pragma warning(disable : 4996)
_CRT_SECURE_NO_WARNINGS
#define ll long long
#define endl '\n'
#define size_of_arrs 17
using namespace std;
// int* NUM_OF_APPOINTMENTS_BOOKED = new int(size);
struct booking {
    string day_name;
    int day, month, year, hour, min;
    int duration;
    string doc_speciality;
    string patient_name, patient_user_name;
    int patient_age;
    bool booked = 0; // 0 for canceled
    int number;
};

struct appointment { // to the patient
    int NUM_OF_APPOINTMENTS_BOOKED = 0;
    booking booked[10] = {};// for patient when he links with
    // the doctor
// bool edit_cancelled = 0; // for patient
    string doctor_name = "df";  // to view for patient
    string doc_username = "df"; // to search for the required doctor
    // int number;
};
// for doctor

struct session {
    int B_hour, B_min, E_hour, E_min;
    bool breaks = 0, booked = 0;
    int number;
};
struct Work_Dates {
    string day = "ss";                // 3la 7asb 3dd ayam el 3yzaha
    int B_hour, B_min, E_hour, E_min; // working hours
    int duration;
    // int num_of_breaks = 0;
    // break_hour* B_break = new break_hour[num_of_breaks];
    // break_hour* E_break = new break_hour[num_of_breaks];
    int num_sessions = 0;
    session All_Sessions[13]; // ta2seem el sa3at (num_of_Ava_appointments)
    // hakaren b break bs
};

// Define a struct to store doctor information
struct doc {
    int number;
    char gender;
    string first_name, last_name;
    string specialty = "sss";
    int years_of_experience;
    int num_of_days = 0; // for one week
    // Work_Dates* Work_Date = new Work_Dates[num_of_days];
    Work_Dates Work_Date[7] = {};
    appointment Appointments; // ma7gooz
    // 3la 7asb 3dd ayam el 3yzaha
    //  int The_price_of_the_check_up;
    int age, ID; // ID = NUM_DOCTORS; -> index
    string user_name, password, email, phone_number;
    int num_of_patients = 0;
    int rate[10] = {};
    float avg_rates = 0;
    int count_of_rates = 0;
    float Fees = 0;
    string day_name = "ssss";
    int searching_times = 0;
};
struct pat {
    string username, password, first_name, last_name;
    int age, ID; // ID = num_of_patient; -> index
    int num_of_appointments_booked = 0;
    int history_list_size = 0;
    appointment appointments[10];
    appointment history[10];
    char gender;
    string phone_number;
};
string days[7]{ "Saturday",  "Sunday",   "Monday", "Tuesday",
               "Wednesday", "Thursday", "Friday" };
string months[12]{ "January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December" };
int month_value[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
struct reference_date {
    int day, year, month, w_day;
};

time_t t = time(0);
tm* tmp = localtime(&t);
void reference_time(int year2, int day1, int& day2);
void leap_year(int YEAR);
int miniMenu();
void font_and_color(int font_size_x = 15, int font_size_y = 15, int color = 7, int bold = 400);
void text_edit(string Text, int font_size_x = 15, int font_size_y = 15, int color = 7, int bold = 400, int m_sec = 0);
void  Doctor_Homepage(doc doctor[], int current_doc);
bool duration_possible(int b_hour, int b_min, int e_hour, int e_min, int sesssion[]);
void input_ava_time(int session[], doc doctor[], int current_doc, int index, int flag, bool add_ava, bool& check_ava);
void Add_Available_Time(int session[], doc doctor[], int current_doc);
void Edit_Available_Time(doc doctor[], pat patient[], int last_patient_array, int current_doc, int session[]);
void Remove_Available_Time(doc doctor[], pat patient[], int last_patient_array, int current_doc);
void View_Patients_with_appointments(doc doctor[], pat patient[], int current_doc);
void Edit_info_doc(doc doctor[], pat patient[], int current_doc);
void display_Avalabile_time(doc doctor[], int current_doc);
string Specialty_Display();
bool search_doc(doc doctor[], int& current_doc, string username, string pass);
bool search_patient(pat patient[], int& current_patient, string username, string pass);
string cin_phone_number();
bool continue_or_exit();
bool confirm();
void view_prof(doc doctor[], int current_doc);
void input_data(doc doctor[], pat patient[], int& last_doc_array, int& last_patient_array);
void save_data(doc doctor[], pat patient[], int last_doc_array, int last_patient_array);
int display_duration(int session[], int b_hour, int b_min, int e_hour, int e_min);
void save_sessions(doc doctor[], int current_doc, int b_h, int b_m, int duration, int index);
void choose_breaks(doc doctor[], int current_doc, int index, bool flag3);
void patient_cancelled(pat patient[], doc doctor[], int current_doc, Work_Dates a, int sess_index, int last_patient_array);
void remove_7ogozat(pat patient[], doc doctor[], int current_doc, int patient_index, int patient_app);
bool alarm_for_doc(pat patient[], doc doctor[], int current_doc, int last_patient_array, Work_Dates b_edit, int Case, int index);
bool check_app_time(int b_h, int b_m, int e_h, int e_m);
int display_day(bool mode, doc doctor[], int current_doc);
string day_Display();
bool str_equal(booking b1, booking b2);
int input(int begin = -1, int end = -1);
int string_to_int(string s);
string cin_username(doc doctor[], pat patient[]);
string cin_password();
bool Login(doc doctor[], int& current_doc, pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array);
///////////////////////////////////////////patient
void History_list(pat patient[], int current_patient, doc doctor[], int last_doc_array);
void history_list_display(pat patient[], int current_patient);
void TIME();
int Agmad_Function_Fel_System(doc doctor[], int last_doc_array);
void RATING(float rate);
float avg_rates(doc suitable_doctor[], int index_doctor, int current_patient, int last_patient_array = 2);
void arrange(doc doctor[], int last_doc_array);
void rating(doc suitable_doctor[], int index_doctor, int current_patient, int last_doc_array);
void Rate();
int dayy(string day);
void calender_date(string* day_name, int& DAY, int& MONTH, int& YEAR, int& w__day);
string calender_date(int day, int month, int year);
void Patient_Homepage(pat patient[], int current_patient);
int cin_day(int month, int year);
int cin_daynum(int& flag);

void Suitable_Doctors_by_speciality(int* doc_num, int last_doc_array, doc suitable_doctor[], doc doctor[], string Specialty = "\0");
bool Suitable_Doctors_by_day_name(int* doc_num, doc suitable_doctor[], string* day_name);
void choose_by_date(int i, doc suitable_doctor[], string* day_name, appointment& suitable_date, int* index, bool& search_for_another_time);
void choose_by_day(int i, doc suitable_doctor[], string* day_name, appointment& suitable_date, int* index, bool& search_for_another_time);
void choose_by_certain_time(int i, int doc_num, appointment& suitable_date, doc suitable_doctor[], int way_number, bool& search_for_another_time, string* day_name, int* index);
void view_suitable_doctor(int i, doc suitable_doctor[], string* day_name, int* index, int& w__day, appointment& suitable_date, int j); // j is for search by name = num_sessions
bool Search_For_Doctors(int i, doc suitable_doctor[], string* day_name, int day, int month, int year, int hour = -1, int min = -1);
void Search_Doc_For_Day(int i, doc suitable_doctor[], string* day_name, int& w__day, appointment& suitable_date, int hour = -1, int min = -1);
void Save_Session_Details(int i, doc suitable_doctor[], int* NUMBER, appointment& suitable_date, string* day_name);//patient
//void searchDoctors(int* doc_num, appointment *suitable_date, int *num_doctor);


void Show_Available_Time(int i, doc suitable_doctor[], string* day_name, int* index, int num_of_iterations, bool edit = 0, appointment suitable_date = {}, int num_doctor = 0);
void booking_confirmation_AndSave(int i, doc suitable_doctor[], doc doctor[], appointment& suitable_date, pat patient[], int current_patient, int last_doc_array);
void edit_appointment(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array);
void delete_appointment(pat patient[], int current_patient, doc doctor[], int last_doc_array, int num = -1, bool history = 0);
void Edit_patient_info(pat patient[], int current_patient, doc doctor[]);
bool view_appointments(pat patient[], int current_patient);
void input_date(appointment& Suitable_Date, string* day_name);
void search_doctor_by_username(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array);
bool book_an_appointment(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array, bool search_doc_by_name = false);
void profile(doc doctor[], int i);
void clear_history(pat patient[], int current_patient);

bool Patient_Modes(pat patient[], int current_patient, doc doctor[], doc suitable_doctor[], int last_doc_array);
bool Doctor_Modes(doc doctor[], int current_doctor, pat patient[], int  last_patient_array, int session[]);
void View_Doctor_info(doc suitable_doctor[], int i);
void Register_as_Doctor(doc doctor[], pat patient[], int& current_doc, int& last_doc_array, int& last_patient_array);

void Register_as_patient(doc doctor[], pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array);
bool Login_and_Register(doc doctor[], int& current_doc, pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array);
void cin_position(int x, int y);
bool today(doc suitable_doctor[], int day, int month, int year, int i, int j, int k);
void patient_profile(pat patient[], int current_patient);
void welcome();