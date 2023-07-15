#pragma once

bool Doctor_Modes(doc doctor[], int current_doctor, pat patient[], int  last_patient_array, int session[])
{
	int choiceChosen = input(1, 9);
	system("CLS");
	TIME();
	do {

		switch (choiceChosen)
		{
		case 1:
			//add available time
			if (doctor[current_doctor].num_of_days == 7)
				cout << "  There are no more days to add.\n\n";
			else
				Add_Available_Time(session, doctor, current_doctor);
			break;
		case 2:
			//edit available time
			if (doctor[current_doctor].num_of_days == 0)
				cout << "  There are no appointments to edit.\n";
			else
			{
				Edit_Available_Time(doctor, patient, last_patient_array, current_doctor, session);
				cout << endl;
			}
			break;

		case 3:

			if (doctor[current_doctor].num_of_days == 0)
			{
				cout << "  There are no appointments to remove.\n";
			}
			else
			{
				//remove
				cout << endl;///will be put in main
				Remove_Available_Time(doctor, patient, last_patient_array, current_doctor);
			}

			break;

		case 4:
			//view patient
			View_Patients_with_appointments(doctor, patient, current_doctor);
			cout << endl;
			break;

		case 5:
			//edit info
			Edit_info_doc(doctor, patient, current_doctor);
			break;

		case 6:
			//view profile
			view_prof(doctor, current_doctor);
			break;
		case 7:
			// view avalible time

			if (doctor[current_doctor].num_of_days == 0)
			{
				cout << "  There are no avalible times to display.\n";
			}
			else display_Avalabile_time(doctor, current_doctor);
			break;

		case 8:
			//logout
			// save_data(doctor, patient, last_doc_array, last_patient_array);
			system("CLS");
			TIME();
			return 1;
		case 9:
			// exit
		   // save_data(doctor, patient, last_doc_array, last_patient_array);
			system("CLS");
			TIME();
			return 0;

		}

		cout << endl;
		choiceChosen = miniMenu();
		system("CLS");
		TIME();

		if (choiceChosen == 10)
		{
			Doctor_Homepage(doctor, current_doctor);
			choiceChosen = input(1, 9);

			system("CLS");
			TIME();
		}
	} while (true);
}
int miniMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "  If you want to";
	SetConsoleTextAttribute(h, 9);
	cout << " Add ";
	SetConsoleTextAttribute(h, 7);
	cout << "another available time->\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(1).\n";
	SetConsoleTextAttribute(h, 7);


	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "Edit ";
	SetConsoleTextAttribute(h, 7);
	cout << "another available time->\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(2).\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "Remove ";
	SetConsoleTextAttribute(h, 7);
	cout << "another available time-> ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(3).\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "View ";
	SetConsoleTextAttribute(h, 7);
	cout << "your patients->\t\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(4).\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to";
	SetConsoleTextAttribute(h, 9);
	cout << " Edit ";
	SetConsoleTextAttribute(h, 7);
	cout << "your info->\t\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(5).\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "View ";
	SetConsoleTextAttribute(h, 7);
	cout << "your profile->\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "        press number(6).\n";


	SetConsoleTextAttribute(h, 7);
	cout << "  If you want to";
	SetConsoleTextAttribute(h, 9);
	cout << " Display ";
	SetConsoleTextAttribute(h, 7);
	cout << "available time->\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(7).\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to";
	SetConsoleTextAttribute(h, 9);
	cout << " Logout";
	SetConsoleTextAttribute(h, 7);
	cout << "->\t\t\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(8).\n";
	SetConsoleTextAttribute(h, 7);


	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "Exit ";
	SetConsoleTextAttribute(h, 7);
	cout << "the program->\t\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(9).\n" << endl;
	SetConsoleTextAttribute(h, 7);

	cout << "  If you want to ";
	SetConsoleTextAttribute(h, 9);
	cout << "Return ";
	SetConsoleTextAttribute(h, 7);
	cout << "to main menu->\t\t ";
	SetConsoleTextAttribute(h, 9);
	cout << "press number(10).\n\n" << endl;
	SetConsoleTextAttribute(h, 7);

	int numberr;

	cout << "  Enter the number of the choice you want : "; numberr = input(1, 10);
	cout << endl;

	return numberr;
}
void TIME()
{
	time_t t = time(0);
	tm* tmp = localtime(&t);
	cout << "  Vezeeta.com \t\t \n";
	cout << "  -------------------------------------------------------------------------------------\n ";
	cout << " " << tmp->tm_hour << " : " << tmp->tm_min << " : " << +tmp->tm_sec;
	cout << "                                                               (" << tmp->tm_mday << "/" << tmp->tm_mon + 1 << "/" << 1900 + tmp->tm_year << ")";
	cout << "\n\n";
}
void  Doctor_Homepage(doc doctor[], int current_doc)
{
	int choice;
	cout << "  \t\t\t\t  WELCOME," << doctor[current_doc].first_name << '!' << endl << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  |To Add available time,   choose 1|   *   |To Edit available time,   choose 2|" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  |To Remove available time,choose 3|   *   |To View your patients,    choose 4|" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  |To Edit your profile,    choose 5|   *   |To View profile,          choose 6|" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  |To View available time,  choose 7|   *   |To logout,                choose 8|" << endl;
	cout << "  -----------------------------------       ------------------------------------" << endl;
	cout << "  --------------------" << endl;
	cout << "  |To Exit,  choose 9|" << endl;
	cout << "  --------------------" << endl << endl;

	cout << "  Enter the number of the choice you want: ";
}
void input_ava_time(int session[], doc doctor[], int current_doc, int index, int flag, bool add_ava, bool& check_ava)
{

	if (flag != 1 && flag != 4)
	{
		int day;
		if (add_ava == 1) {
			day = display_day(1, doctor, current_doc) + 1; //choose day
			index = day - 1;
		}

		cout << endl;


		if (add_ava) //if it is add available time function
		{
			for (int i = 0; i < 7; i++)
			{
				if (doctor[current_doc].Work_Date[i].day == days[day - 1])
				{
					system("CLS");
					TIME();
					cout << "  You already work at that Day! Please choose another one!" << endl;
					check_ava = 1;
					return;
				}
			}
		}
		doctor[current_doc].Work_Date[index].day = days[day - 1];
	}

	int b_hour, b_min, e_hour, e_min;
	int session_period;

	do {

		cout << "  *** NOTE WE ARE USING 24 HOUR FORMATE ***\n\n";
		cout << "  Enter start hour: "; b_hour = input(0, 24);
		cout << "  Enter start min: "; b_min = input(0, 59);
		cout << "  Enter end hour: ";  e_hour = input(0, 24);
		cout << "  Enter end min: ";  e_min = input(0, 59);


		//check if end hour < start hour
		if (!check_app_time(b_hour, b_min, e_hour, e_min))
		{
			continue;
		}

		//chech if working hours are not compatible with any existing duration 


		if (duration_possible(b_hour, b_min, e_hour, e_min, session) == 0) continue;

		doctor[current_doc].Work_Date[index].B_hour = b_hour;
		doctor[current_doc].Work_Date[index].B_min = b_min;
		doctor[current_doc].Work_Date[index].E_hour = e_hour;
		doctor[current_doc].Work_Date[index].E_min = e_min;
		cout << endl;

		if (flag != 4)
		{

			session_period = display_duration(session, b_hour, b_min, e_hour, e_min) + 1;
			cout << endl;
			doctor[current_doc].Work_Date[index].duration = session[session_period - 1];
		}

		if (flag == 4)
		{ //get the order of duration in duration array
			session_period = 4 - ((60 - doctor[current_doc].Work_Date[index].duration) / 15);
		}
		// check on time and duration chosen
		if (((e_hour * 60 + e_min) - (b_hour * 60 + b_min)) % session[session_period - 1] != 0)
		{
			cout << "  Your working hours are not compatible with the duration you entered! \n\n";
		}
		else
		{
			doctor[current_doc].Work_Date[index].num_sessions = ((e_hour * 60 + e_min) - (b_hour * 60 + b_min)) / session[session_period - 1];
			break;
		}

	} while (true);
	save_sessions(doctor, current_doc, b_hour, b_min, session[session_period - 1], index);

	if (flag != 4)  choose_breaks(doctor, current_doc, index, 0);
}
void Add_Available_Time(int session[], doc doctor[], int current_doc)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	bool check_ava = 0; //3lshan at2kd 2n elm3ad mawgood wla la 3lshan lw mawgood m4 haynf3 tdeef
	int number;

	cout << " **** ADD AVALIBLE TIME *****\n\n";
	if (!continue_or_exit())
	{
		return;
	}

	if (doctor[current_doc].num_of_days != 0)
		display_Avalabile_time(doctor, current_doc);


	cout << endl;
	cout << "             ADD AVAILABLE TIME                \n";
	cout << "  ------------------------------------------\n\n";

	cout << "  How many days you want to add? ";

	do {
		number = input(1, 7);
		cout << doctor[current_doc].num_of_days << endl;
		if (number > (7 - doctor[current_doc].num_of_days))
		{
			cout << "  You can add number of days up to " << (7 - doctor[current_doc].num_of_days) << " only !" << endl;
		}
		else break;
	} while (true);

	for (int i = 0; i < number; i++)
	{
		check_ava = 0;
		system("CLS");
		TIME();
		cout << "\n  Enter the data of day " << i + 1 << ":\n";
		cout << "  -------------------------------------\n\n";

		input_ava_time(session, doctor, current_doc, 0, 0, 1, check_ava); //0,0 useless in add function, but important for edit function 
		//1 is a flag for input ava time that we are in the add function 
		if (check_ava)
		{
			i--;
			continue;
		}
		doctor[current_doc].num_of_days++;
	}
	system("CLS");
	TIME();
	cout << "  Do you want to view your available times?(y/n) : ";
	if (confirm())
	{
		display_Avalabile_time(doctor, current_doc);
		cout << endl;

	}

	SetConsoleTextAttribute(h, 6);
	cout << "  Everything was successfully added!! \n\n";
	SetConsoleTextAttribute(h, 7);

	cout << "  You will be directed to the main menu, thank you!" << endl;

}
void Edit_Available_Time(doc doctor[], pat patient[], int last_patient_array, int current_doc, int session[])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << " **** EDIT AVALIBLE TIME *****\n\n";
	if (!continue_or_exit())
	{
		return;
	}
	cout << endl;
	display_Avalabile_time(doctor, current_doc);
	cout << "\n  \t\t    Edit Avalabile Time\n";
	cout << "  -----------------------------------------------------------\n\n";
	int day_choice, edit_choice;
	bool work_day;

	day_choice = display_day(0, doctor, current_doc) + 1;

	Work_Dates b_edit = doctor[current_doc].Work_Date[day_choice - 1];

	system("CLS");
	TIME();

	cout << "  Enter (1) to edit the day.\n  Enter (2) to edit the duration. (NOTE: you will edit time interval as well) \n  Enter (3) to edit breaks.\n  Enter (4) to edit the time interval.\n\n";

	cout << "  Enter your choice: ";
	edit_choice = input(1, 4);

	bool flag = 1, exist;
	int edit_day;

	switch (edit_choice)
	{
	case 1:

		if (alarm_for_doc(patient, doctor, current_doc, last_patient_array, b_edit, 1, day_choice - 1) == 0)
		{
			cout << "  You will be directed to the main menu." << endl;
			return;
		}

		edit_day = display_day(1, doctor, current_doc) + 1;

		doctor[current_doc].Work_Date[day_choice - 1].day = days[edit_day - 1];
		//assign old details with new day name to the new index
		doctor[current_doc].Work_Date[edit_day - 1] = doctor[current_doc].Work_Date[day_choice - 1];
		doctor[current_doc].Work_Date[day_choice - 1] = {}; //old day details= 0
		break;

	case 2:
		if (alarm_for_doc(patient, doctor, current_doc, last_patient_array, b_edit, 1, day_choice - 1) == 0)
		{
			cout << "  You will be directed to the main menu" << endl;
			return;
		}
		do {

			input_ava_time(session, doctor, current_doc, day_choice - 1, 1, 0, flag);

			if (b_edit.duration == doctor[current_doc].Work_Date[day_choice - 1].duration)
			{
				cout << "  The duration is the same!! INPUT AGAIN!!\n";
				continue;
			}
			else break;

		} while (true);

		break;
	case 3:
		bool break_not_exist;

		do {
			// to handle do while
			break_not_exist = 0;

			choose_breaks(doctor, current_doc, day_choice - 1, 1);

			for (int i = 0; i < doctor[current_doc].Work_Date[day_choice - 1].num_sessions; i++)
			{
				if (doctor[current_doc].Work_Date[day_choice - 1].All_Sessions[i].breaks !=
					b_edit.All_Sessions[i].breaks)
				{
					break_not_exist = 1; // to make sure that he already make edits
					break;
				}
			}

			if (!break_not_exist)
			{
				cout << "  You didn't make any changes!! Input again!! \n";
				system("CLS");
				TIME();
				continue;
			}

			if (alarm_for_doc(patient, doctor, current_doc, last_patient_array, b_edit, 3, day_choice - 1) == 0)
			{
				doctor[current_doc].Work_Date[day_choice - 1] = b_edit;
				cout << "  You will be directed to the main menu." << endl;
				return;
			}

		} while (!break_not_exist);

		break;

	case 4:

		do {

			input_ava_time(session, doctor, current_doc, day_choice - 1, 4, 0, flag);

			if (b_edit.B_hour == doctor[current_doc].Work_Date[day_choice - 1].B_hour &&
				b_edit.B_min == doctor[current_doc].Work_Date[day_choice - 1].B_min &&
				b_edit.E_hour == doctor[current_doc].Work_Date[day_choice - 1].E_hour &&
				b_edit.E_min == doctor[current_doc].Work_Date[day_choice - 1].E_min)
			{
				cout << "  You did not make any changes!! INPUT AGAIN!!\n";
				continue;
			}

			if (alarm_for_doc(patient, doctor, current_doc, last_patient_array, b_edit, 4, day_choice - 1) == 0)
			{
				doctor[current_doc].Work_Date[day_choice - 1] = b_edit;
				cout << "  You will be directed to the main menu" << endl;
				return;
			}
			else break;

		} while (true);

		break;
	}

	system("CLS");
	TIME();
	cout << endl << "  Do you wish to edit another time?(y/n) : ";
	if (confirm())
	{
		system("CLS");
		TIME();
		Edit_Available_Time(doctor, patient, last_patient_array, current_doc, session);
	}
	else {

		cout << "  Do you want to view your available times?(y/n): ";
		if (confirm())
		{
			display_Avalabile_time(doctor, current_doc);
		}

		SetConsoleTextAttribute(h, 6);
		cout << "  Changes has been saved!! \n\n";
		SetConsoleTextAttribute(h, 7);
		cout << "  You will be directed to main menu." << endl << endl;
		return;
		// call menu fncout.
	}
}
void Remove_Available_Time(doc doctor[], pat patient[], int last_patient_array, int current_doc) {
	cout << " **** REMOVE AVALIBLE TIME *****\n\n";
	if (!continue_or_exit())
	{
		return;
	}

	display_Avalabile_time(doctor, current_doc);
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "  Would you like to remove all avalible times? (y/n): ";
	if (confirm())
	{
		if (doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED > 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "  All patients appointment's will be cancelled.Do you wish to continue with this operation? (y/n): ";
			SetConsoleTextAttribute(h, 7);
			if (confirm())
			{
				for (int i = 0; i < 7; i++) doctor[current_doc].Work_Date[i] = {};

				doctor[current_doc].num_of_days = 0;
				doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED = 0;
				doctor[current_doc].Appointments = {};

				for (int i = 0; i < last_patient_array; i++)
				{
					for (int j = 0; j < patient[i].num_of_appointments_booked; j++)
					{
						if (patient[i].appointments[j].doc_username == doctor[current_doc].user_name
							&& patient[i].appointments[j].booked[0].booked == 1)
						{
							patient[i].appointments[j].booked[0].booked = 0;
						}
					}
				}
			}

		}
		else {

			for (int i = 0; i < 7; i++) doctor[current_doc].Work_Date[i] = {};
			doctor[current_doc].num_of_days = 0;
		}


	}
	else {

		cout << endl;

		bool work_day;
		int day_choice = display_day(0, doctor, current_doc) + 1;
		system("CLS");
		TIME();

		if (alarm_for_doc(patient, doctor, current_doc,
			last_patient_array, doctor[current_doc].Work_Date[day_choice - 1], 1, day_choice - 1) == 0)
		{
			cout << "  You will be directed to the main menu." << endl;
			return;
		}
		doctor[current_doc].Work_Date[day_choice - 1] = {};
		doctor[current_doc].num_of_days--;

		system("CLS");
		TIME();


		if (doctor[current_doc].num_of_days != 0) {
			cout << "  Do you wish to remove another time?(y/n) : ";
			if (confirm())
			{
				system("CLS");
				TIME();
				Remove_Available_Time(doctor, patient, last_patient_array, current_doc);
			}
			else {
				cout << "  Do you want to view your avalabile times?(y/n) : ";
				if (confirm())
				{

					display_Avalabile_time(doctor, current_doc);
					cout << endl;

				}
			}
		}

	}

	SetConsoleTextAttribute(h, 6);
	cout << "  Everything has been sucessfully removed!!\n\n" << endl;
	SetConsoleTextAttribute(h, 7);

	cout << "  You will be directed to main menu." << endl;
	return;

}
void View_Patients_with_appointments(doc doctor[], pat patient[], int current_doc)
{

	cout << "                             Patients with appointments                           " << "\n";
	cout << "         -----------------------------------------------------------------" << "\n\n";

	if (doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED == 0) cout << "                   !!!! You do not have any appointments !!!!\n\n";
	else
	{

		cout << "  -----------------------------------------------------------------------------------\n";
		cout << "  No.|   Day   |   Date   | Time | Duration | Patient name - patient username \n";
		cout << "  -----------------------------------------------------------------------------------\n\n";

		for (int i = 0; i < doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED; i++)
		{
			cout << "  " << setw(2) << setfill(' ') << i + 1 << ".|" << setw(9) << setfill(' ') << doctor[current_doc].Appointments.booked[i].day_name << "|";
			cout << setw(2) << setfill('0') << doctor[current_doc].Appointments.booked[i].day << "/"
				<< setw(2) << setfill('0') << doctor[current_doc].Appointments.booked[i].month << "/"
				<< doctor[current_doc].Appointments.booked[i].year << "|"
				<< setw(2) << setfill(' ') << doctor[current_doc].Appointments.booked[i].hour << ":"
				<< setw(2) << setfill('0') << doctor[current_doc].Appointments.booked[i].min << " |"
				<< "    " << doctor[current_doc].Appointments.booked[i].duration << "    " << "| "
				<< doctor[current_doc].Appointments.booked[i].patient_name
				<< " - " << doctor[current_doc].Appointments.booked[i].patient_user_name << "\n\n";
			cout << "  -----------------------------------------------------------------------------------\n";
		}
	}
}
void Edit_info_doc(doc doctor[], pat patient[], int current_doc)
{
	cout << " **** EDIT PROFILE ****\n\n";
	if (!continue_or_exit())
	{
		return;
	}

	view_prof(doctor, current_doc);

	string newusername, newpassword, newname1, newfield, newphonenumber, newname2, adjust_speciality;
	int newage, newnumofexpe, new_price;

	int option;
	cout << "  Edit your profile info:\n  ------------------------------------------------------\n  Press (1) to edit username. \n  Press (2) to edit password. \n  Press (3) to edit specilaty. \n  Press (4) to edit name. \n  Press (5) to edit age.\n  press (6) to edit number of experience.\n  press (7) to edit phone number.\n  press (8) to edit price of session.\n";
	cout << "\n\n  Enter your choice :";
	option = input(1, 8);


	switch (option)
	{
	case 1:

		cout << "  Enter username: ";  newusername = cin_username(doctor, patient);
		cout << endl << "  Do you want to confirm?(y/n): ";
		if (confirm())
		{
			for (int i = 0; i < size_of_arrs; i++) //change doc username of the patients that booked with him.
			{
				for (int j = 0; j < patient[i].num_of_appointments_booked; j++)
				{
					if (patient[i].appointments[j].doc_username == doctor[current_doc].user_name)
					{
						patient[i].appointments[j].doc_username = newusername; //change the username to the new one.
					}
				}
			}
			doctor[current_doc].user_name = newusername;
		}

		break;
	case 2:
		cout << "  Enter password: "; newpassword = cin_password();
		cout << endl << "  Do you want to confirm?(y/n): ";
		if (confirm())
		{
			doctor[current_doc].password = newpassword;
		}

		cout << endl;

		break;
	case 3:

		cout << "\n"; adjust_speciality = Specialty_Display();

		cout << endl << "  Do you want to confirm?(y/n): ";

		if (confirm()) {

			doctor[current_doc].specialty = adjust_speciality;
			for (int i = 0; i < size_of_arrs; i++) //change doc speciality to doctors patients.
			{
				for (int j = 0; j < patient[i].num_of_appointments_booked; j++)
				{

					if (patient[i].appointments[j].doc_username == doctor[current_doc].user_name) //the patients that booked with him.
					{
						patient[i].appointments[j].booked[0].doc_speciality = doctor[current_doc].specialty; //change the speciality.
					}
				}
			}
		}
		break;
	case 4:

		cout << "  Enter first name: "; cin >> newname1;
		cout << "  Enter last name: "; cin >> newname2;

		cout << endl << "\n  Do you want to confirm?(y/n): ";


		if (confirm())
		{
			doctor[current_doc].first_name = newname1;
			doctor[current_doc].last_name = newname2;

			for (int i = 0; i < size_of_arrs; i++)
			{
				for (int j = 0; j < patient[i].num_of_appointments_booked; j++)//change doc name of the patients that booked with him.
				{
					if (patient[i].appointments[j].doc_username == doctor[current_doc].user_name) //search using username bec its unique
					{
						patient[i].appointments[j].doctor_name = newname1;//change the name.
					}
				}
			}
		}


		break;
	case 5:cout << "  Enter age: ";  newage = input(24, 100);
		cout << endl << "  Do you want to confirm?(y/n): ";
		if (confirm()) { doctor[current_doc].age = newage; }
		break;
	case 6:
		cout << "  Enter number of experience: ";
		newnumofexpe = input(0, doctor[current_doc].age - 25);
		cout << endl << "  Do you want to confirm?(y/n): ";
		if (confirm()) { doctor[current_doc].years_of_experience = newnumofexpe; }
		break;
	case 7:
		cout << "  Enter phone number: ";
		newphonenumber = cin_phone_number();
		cout << endl << "  Do you want to confirm?(y/n): ";
		if (confirm()) { doctor[current_doc].phone_number = newphonenumber; }
		break;
	case 8:
		cout << "  Enter new price of session: ";
		new_price = input();
		cout << "  Do you want to confirm?(y/n): ";
		if (confirm()) { doctor[current_doc].Fees = new_price; }
		break;
	default:
		cout << "  INVALID VALUE!!" << endl;
		Edit_info_doc(doctor, patient, current_doc);
	}

	system("CLS");
	TIME();
	cout << "\n  Do you wish to edit something else?(y/n) : ";

	if (confirm())
	{
		system("CLS");
		TIME();
		Edit_info_doc(doctor, patient, current_doc);
	}
	else {
		cout << "  Do you want to view your profile information?(y/n): ";
		if (confirm())
		{
			view_prof(doctor, current_doc);
		}
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 6);
		cout << "  Changes has been saved!!\n\n";
		SetConsoleTextAttribute(h, 7);

		cout << "  You will be directed to main menu." << endl;
		return;
	}
}
void display_Avalabile_time(doc doctor[], int current_doc)
{

	cout << "  ---------------------------------------------------------------" << endl;
	cout << "  No.|   Day   | Start hour | End hour | Duration | no.sessions |" << endl;
	cout << "  ---------------------------------------------------------------" << endl << endl;

	int ind = 0;

	for (int i = 0; i < 7; i++)
	{
		if (doctor[current_doc].Work_Date[i].day == "ss") continue;


		//ss like null
		ind++;
		cout << "  ---------------------------------------------------------------" << endl;
		cout << "  " << ind << ". |" << setw(9) << setfill(' ') << doctor[current_doc].Work_Date[i].day;

		cout << "  |  " << setw(2) << doctor[current_doc].Work_Date[i].B_hour << " : "
			<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[i].B_min << "   | ";

		cout << setw(2) << setfill(' ') << doctor[current_doc].Work_Date[i].E_hour << " : "
			<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[i].E_min;

		cout << "  |    " << doctor[current_doc].Work_Date[i].duration;
		cout << "    |      " << setw(2) << setfill(' ') << doctor[current_doc].Work_Date[i].num_sessions << "    |\n";
		cout << "  ---------------------------------------------------------------" << endl;


		bool flag = 0;
		for (int j = 0; j < doctor[current_doc].Work_Date[i].num_sessions; j++)
		{

			if (doctor[current_doc].Work_Date[i].All_Sessions[j].breaks == 1) {

				if (flag == 0) { // this flag to not print this cout more than once
					flag = 1;
					cout << endl << "  The breaks in between your working hours:" << endl;
					cout << "  --------------------------------------------------\n" << endl;
					cout << "  ----------------------------\n";
				}

				cout << "  |From : " << doctor[current_doc].Work_Date[i].All_Sessions[j].B_hour << " : "
					<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[i].All_Sessions[j].B_min << "  To: ";

				cout << doctor[current_doc].Work_Date[i].All_Sessions[j].E_hour << " : "
					<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[i].All_Sessions[j].E_min << " |";
				cout << "\n  ----------------------------\n";

			}

		}

	}

}
void Register_as_Doctor(doc doctor[], pat patient[], int& current_doc, int& last_doc_array, int& last_patient_array)
{
	system("CLS");
	doctor[last_doc_array].specialty = Specialty_Display();
	system("CLS");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\t\t\t\t\t\t ----------------------------------------------------------------\t\t\t\n";
	cout << "\t\t\t\t\t\t | "; SetConsoleTextAttribute(h, 9); cout << " Register in Vezeeta"; SetConsoleTextAttribute(h, 7);
	cout << "                                          |\t\t\t\n";
	cout << "\t\t\t\t\t\t |---------------------------------------------------------------|\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     First Name      |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     Last Name       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |         Age         |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     Phone Number    |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |      Username       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |      Password       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     Speciality      |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |   Fees Of Session   |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    | Years of experience |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |       Gender        |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |  1.Male / 2.Female  |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          ---------------                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          | Register [1]|                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          ---------------                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t ----------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t\t\t\t ";

	cin_position(78, 23);
	cout << doctor[last_doc_array].specialty;
	cin_position(78, 5);
	cin >> doctor[last_doc_array].first_name;
	cin_position(78, 8);
	cin.ignore(); cin >> doctor[last_doc_array].last_name;
	cin_position(78, 11);
	cin.ignore(); doctor[last_doc_array].age = input(24, 100);
	cin_position(78, 14);
	doctor[last_doc_array].phone_number = cin_phone_number();
	cin_position(78, 17);
	doctor[last_doc_array].user_name = cin_username(doctor, patient);
	cin_position(78, 20);
	doctor[last_doc_array].password = cin_password();
	cin_position(78, 26);
	doctor[last_doc_array].Fees = input(0, 100000);
	cin_position(78, 29);
	doctor[last_doc_array].years_of_experience = input(0, doctor[last_doc_array].age - 24);
	cin_position(78, 32);
	if (input(1, 2) == 1)
	{
		doctor[last_doc_array].gender = 'm';
		cin_position(78, 32);
		cout << "Male";
	}
	else
	{
		doctor[last_doc_array].gender = 'f';
		cin_position(78, 32);
		cout << "Female";
	}
	cin_position(60, 47);
	input(1, 1);
	last_doc_array++;
	system("CLS");


	//  TIME();

}
void Register_as_patient(doc doctor[], pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array)
{
	system("CLS");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


	cout << "\t\t\t\t\t\t ----------------------------------------------------------------\t\t\t\n";
	cout << "\t\t\t\t\t\t | "; SetConsoleTextAttribute(h, 9); cout << " Register in Vezeeta"; SetConsoleTextAttribute(h, 7);
	cout << "                                          |\t\t\t\n";
	cout << "\t\t\t\t\t\t |---------------------------------------------------------------|\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     First Name      |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     Last Name       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |         Age         |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |     Phone Number    |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |      Username       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |      Password       |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |       Gender        |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |    |  1.Male / 2.Female  |                                    |\t\t\t\n";
	cout << "\t\t\t\t\t\t |     ---------------------                                     |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          ---------------                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          | Register [1]|                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                          ---------------                      |\t\t\t\n";
	cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
	cout << "\t\t\t\t\t\t ----------------------------------------------------------------\t\t\t\n\n";
	cout << "\t\t\t\t\t\t ";

	cin_position(78, 5);
	cin >> patient[last_patient_array].first_name;
	cin_position(78, 8);
	cin.ignore(); cin >> patient[last_patient_array].last_name;
	cin_position(78, 11);
	cin.ignore(); doctor[last_doc_array].age = input(0, 100);
	cin_position(78, 14);
	patient[last_patient_array].phone_number = cin_phone_number();
	cin_position(78, 17);
	patient[last_patient_array].username = cin_username(doctor, patient);
	cin_position(78, 20);
	patient[last_patient_array].password = cin_password();
	cin_position(78, 24);
	if (input(1, 2) == 1)
	{
		doctor[last_doc_array].gender = 'm';
		cin_position(78, 24);
		cout << "Male";
	}
	else
	{
		doctor[last_doc_array].gender = 'f';
		cin_position(78, 24);
		cout << "Female";
	}
	cin_position(60, 34);
	input(1, 1);
	last_patient_array++;
	system("CLS");

}
bool Login(doc doctor[], int& current_doc, pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool new_pass = false;
	int num;
	string user, pass;
	system("CLS");
	do {
		system("CLS");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cin_position(0, 0);
		int index = 0;
		string o(36, ' ');
		char ch = '\0';
		string var = "\0";
		int count = 0;
		while (true)
		{
			cout << "\t\t\t\t\t\t ---------------------------------------------------------------- \t\t\t\n";
			cout << "\t\t\t\t\t\t |"; SetConsoleTextAttribute(h, 9); cout << " Login into Vezeeta"; SetConsoleTextAttribute(h, 7);
			cout << "                                            |\t\t\t\n";
			cout << "\t\t\t\t\t\t |---------------------------------------------------------------|\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t |     -------------------                                       |\t\t\t\n";
			if (count == 0)cout << "\t\t\t\t\t\t |    |     Username      |  " << var << o << "|\t\t\t\n";
			if (count == 1)cout << "\t\t\t\t\t\t |    |     Username      |  " << left << setw(36) << user << "| \t\t\t\n";
			cout << "\t\t\t\t\t\t |     -------------------                                       |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t |     -------------------                                       |\t\t\t\n";
			if (count == 0)cout << "\t\t\t\t\t\t |    |     Password      |                                      |\t\t\t\n";
			if (count == 1)cout << "\t\t\t\t\t\t |    |     Password      |  " << var << o << "|\t\t\t\n";
			cout << "\t\t\t\t\t\t |     -------------------                                       |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                       -----------                             |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                      | Login [1] |                            |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                       -----------                             |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                  (Forgot your password? [2])  |\t\t\t\n";
			cout << "\t\t\t\t\t\t |                                                               |\t\t\t\n";
			cout << "\t\t\t\t\t\t ---------------------------------------------------------------- \t\t\t\n\n";
			cout << "\t\t\t\t\t\t  ";
			cin_position(54, 4);
			SetConsoleTextAttribute(h, 48);
			cout << "                     ";
			cin_position(54, 5);
			SetConsoleTextAttribute(h, 48);
			cout << "      Username       ";
			cin_position(54, 6);
			SetConsoleTextAttribute(h, 48);
			cout << "                     ";
			SetConsoleTextAttribute(h, 7);
			//////////////////////
			cin_position(54, 8);
			SetConsoleTextAttribute(h, 48);
			cout << "                     ";
			cin_position(54, 9);
			SetConsoleTextAttribute(h, 48);
			cout << "      Password       ";
			cin_position(54, 10);
			SetConsoleTextAttribute(h, 48);
			cout << "                     ";
			SetConsoleTextAttribute(h, 7);
			////////////
			cin_position(71, 14);
			SetConsoleTextAttribute(h, 48);
			cout << "              ";
			cin_position(71, 15);
			SetConsoleTextAttribute(h, 48);
			cout << "   Login [1]  ";
			cin_position(71, 16);
			SetConsoleTextAttribute(h, 48);
			cout << "              ";
			SetConsoleTextAttribute(h, 7);
			cin_position(0, 0);
			ch = _getch();

			if (ch == '\b' && var == "\0")  continue; //new
			if (ch == '\r')  count++;
			if (ch == '\r' && count == 2)
			{
				pass = var;
				o = "                                    ";
				;				cin_position(60, 20);
				if (input(1, 2) == 1)
				{
					cin_position(60, 20);
					cout << " ";
					if (search_patient(patient, current_patient, user, pass))
					{

						cin_position(71, 21);
						SetConsoleTextAttribute(h, 8);
						cout << "  Loading....";
						SetConsoleTextAttribute(h, 7);
						Sleep(500 + rand() % 3500);
						cin_position(71, 21);
						cout << "             ";
						cin_position(71, 14);
						SetConsoleTextAttribute(h, 160);
						cout << "              ";
						cin_position(71, 15);
						SetConsoleTextAttribute(h, 160);
						cout << "    Login     ";
						cin_position(71, 16);
						SetConsoleTextAttribute(h, 160);
						cout << "              ";
						cin_position(0, 0);
						Sleep(500 + rand() % 3500);
						SetConsoleTextAttribute(h, 7);
						cin_position(67, 21);
						SetConsoleTextAttribute(h, 10);
						cout << "  Login Successfully.\n\n";
						Sleep(500 + rand() % 3500);
						cin_position(67, 21);
						cout << "                     ";
						Sleep(500 + rand() % 3500);
						cin_position(60, 21);
						cout << "  you will be directed to the homepage now.\n";
						Sleep(500 + rand() % 3500);
						cin_position(60, 21);
						cout << "                                             \n";
						cin_position(71, 21);
						SetConsoleTextAttribute(h, 8);
						cout << "  Loading...\n\n";
						Sleep(500 + rand() % 3500);
						SetConsoleTextAttribute(h, 7);
						system("CLS");
						return true;
					}
					else if (search_doc(doctor, current_doc, user, pass))
					{
						cin_position(71, 21);
						SetConsoleTextAttribute(h, 8);
						cout << "  Loading....";
						SetConsoleTextAttribute(h, 7);
						Sleep(500 + rand() % 3500);
						cin_position(71, 21);
						cout << "             ";
						cin_position(71, 14);
						SetConsoleTextAttribute(h, 160);
						cout << "              ";
						cin_position(71, 15);
						SetConsoleTextAttribute(h, 160);
						cout << "    Login     ";
						cin_position(71, 16);
						SetConsoleTextAttribute(h, 160);
						cout << "              ";
						cin_position(0, 0);
						Sleep(500 + rand() % 3500);
						SetConsoleTextAttribute(h, 7);
						cin_position(67, 21);
						SetConsoleTextAttribute(h, 10);
						cout << "  Login Successfully.\n\n";
						Sleep(500 + rand() % 3500);
						cin_position(67, 21);
						cout << "                     ";
						Sleep(500 + rand() % 3500);
						cin_position(60, 21);
						cout << "  you will be directed to the homepage now.\n";
						Sleep(500 + rand() % 3500);
						cin_position(60, 21);
						cout << "                                             \n";
						cin_position(71, 21);
						SetConsoleTextAttribute(h, 8);
						cout << "  Loading...\n\n";
						Sleep(500 + rand() % 3500);
						SetConsoleTextAttribute(h, 7);
						system("CLS");
						return false;
					}
					else
					{
						cin_position(71, 21);
						SetConsoleTextAttribute(h, 8);
						cout << "  Loading....";
						Sleep(500 + rand() % 3500);
						cin_position(77, 5);
						SetConsoleTextAttribute(h, 4);  cout << user;
						cin_position(77, 9);
						SetConsoleTextAttribute(h, 4);  cout << pass;
						cin_position(77, 11);
						SetConsoleTextAttribute(h, 4);
						cout << "\"Invalid Password or Username\"";

						cin_position(71, 14);
						SetConsoleTextAttribute(h, 79);
						cout << "              ";
						cin_position(71, 15);
						SetConsoleTextAttribute(h, 79);
						cout << "    Login     ";
						cin_position(71, 16);
						SetConsoleTextAttribute(h, 79);
						cout << "              ";
						SetConsoleTextAttribute(h, 7);
						cin_position(71, 21);
						cout << "             ";
						cin_position(0, 0);
						Sleep(500 + rand() % 3500);


						break;

					}
				}
				else
				{
					cout << "   Enter the new password : ";
					pass = cin_password();
					search_doc(doctor, current_doc, user, pass);
					search_patient(patient, current_patient, user, pass);
					break;
				}
			}
			if (ch == '\b' && index >= 1)
			{
				var.pop_back();
				cout << "\b \b";
				index--;
				o += " "; //new
				continue;
			}
			if (ch != '\r')
			{
				var += ch;
				o += "\b";
			}
			system("CLS");
			index++;
			if (ch == '\r' && count == 1)
			{
				user = var;
				var = "\0";
				o = "                                    ";
			}
		}

		if (index < var.size() && index >0) var.erase(index); // to check if index in range,if not,there will be error
		else if (index == 0) var.clear(); // if index 0,that means user backspaced everything,so clear string.

	} while (true);
}

bool Login_and_Register(doc doctor[], int& current_doc, pat patient[], int& current_patient, int& last_doc_array, int& last_patient_array)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	////system("CLS");
	//SetConsoleTextAttribute(h, 9);
	//cout << "\n\t\t\t\t\t\t\t\t\t W E L C O M E   T O   V E Z E E T A\t\t\t\n";
	//SetConsoleTextAttribute(h, 7);
	//cout << "\t\t\t\t\t\t ---------------------------------------------------------------------------------\t\t\t\t" << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t  --------------                    -------------------\t\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t |  Login [1]   |                   |   Register  [2]  |\t\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t --------------                     ------------------\t\t\t\t" << endl;
	cout << endl;
	cout << endl;
	cin_position(68, 11);
	if (input(1, 2) == 2)
	{
		system("CLS");
		cout << "\n\n\n";
		cout << "\t\t\t\t\t  ---------------------------                     ------------------------------\n";
		cout << "\t\t\t\t\t |  Register as Doctor [1]   |                   |     Register as Patient [2]   |\n";
		cout << "\t\t\t\t\t  ---------------------------                     ------------------------------\n";
		cout << "\n\n";
		cin_position(68, 6);
		if (input(1, 2) == 1) Register_as_Doctor(doctor, patient, current_doc, last_doc_array, last_patient_array);
		else Register_as_patient(doctor, patient, current_patient, last_doc_array, last_patient_array);

		save_data(doctor, patient, last_doc_array, last_patient_array);

		SetConsoleTextAttribute(h, 6);
		cout << "\n\n";
		cout << "\t\t\t\t\t\t  * * * * * * * * * * * * *   \t\t\t\n";
		cout << "\t\t\t\t\t\t * Registered Successfully *  \t\t\t\n";
		cout << "\t\t\t\t\t\t  * * * * * * * * * * * * *   \t\t\t\n";
		cout << "\n\n";
		SetConsoleTextAttribute(h, 7);
	}

	return Login(doctor, current_doc, patient, current_patient, last_doc_array, last_patient_array);

}
string Specialty_Display() {

	string specialties[10] = { "Anesthesiology","Cardiology", "Dermatology","Endocrinology", "Gastroenterology","Genital pathology","Hematology","immunology","Medical examiner", "Nephrology" };

	cout << "  Please, choose the speciality:\n";
	cout << "  -----------------------------------------\n\n";
	for (int i = 0; i < 10; ++i) {
		cout << "  " << setw(2) << setfill(' ') << i + 1 << ". " << specialties[i] << ".\n\n";
	}

	cout << "\n  Your choice: ";

	int choice; choice = input(1, 10);
	return specialties[choice - 1];
}
bool search_doc(doc doctor[], int& current_doc, string username, string pass)
{
	for (int i = 0; i < size_of_arrs; i++)
	{
		if (username == doctor[i].user_name)
		{
			current_doc = i;
			if (pass == doctor[i].password) return 1;
			else {
				pass = doctor[i].password; return 0;
			}
		}
	}
	return 0;   //username doesn't exist
}
bool search_patient(pat patient[], int& current_patient, string username, string pass)
{
	for (int i = 0; i < size_of_arrs; i++)
	{
		if (patient[i].username == username)
		{
			current_patient = i;
			if (patient[i].password == pass) return 1;
			else { patient[i].password = pass; return 0; }
		}
	}
	return 0;
}
string cin_password()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int index = 0;
	char ch = '\0';
	string pass;

	while (true)
	{
		ch = _getch();

		if (ch == '\r')
		{
			//if(pass.empty()) continue; //if(index == 0)		
			if (pass.size() < 4)
			{
				SetConsoleTextAttribute(h, 4);
				cin_position(78, 20);
				cout << "Password must be at least 4 characters";
				Sleep(1000);
				SetConsoleTextAttribute(h, 7);
				cin_position(78, 20);
				cout << "                                   |   \t\t\t";
				cin_position(78, 20);
				for (int i = 0; i < pass.size(); i++)
					cout << "*";
				continue;
			}
			return pass; // enter
		}
		if (ch == '\b' && index >= 1)
		{
			pass.pop_back();
			cout << "\b \b";
			index--;
			continue;
		}
		pass += ch;
		cout << "*";
		index++;
	}
	if (index < pass.size() && index >0) pass.erase(index); // to check if index in range,if not,there will be error
	else if (index == 0) pass.clear(); // if index 0,that means user backspaced everything,so clear string.

}
string cin_phone_number()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string s;
	cin >> s;
	cin.ignore();
	if ((s.size() == 11) && (s[0] == '0') && (s[1] == '1'))
	{
		if (s[2] == '0' || s[2] == '5' || s[2] == '1' || s[2] == '2')
		{

			return s;
		}
	}
	SetConsoleTextAttribute(h, 4);
	cin_position(78, 14);
	cout << "*Invalid phone number.Enter again." << endl;
	Sleep(1000);
	SetConsoleTextAttribute(h, 7);
	cin_position(78, 14);
	cout << "                                   ";
	cin_position(78, 14);
	return cin_phone_number();
}
string cin_username(doc doctor[], pat patient[])
{
	string un;
	cin >> un;
	cin.ignore();

	for (int i = 0; i < size_of_arrs; i++)
	{
		if (un == doctor[i].user_name || un == patient[i].username)  // the username must be unique
		{
			cout << "ALREADY EXIST !! please try another one.\n";
			un = cin_username(doctor, patient);
		}
	}
	return un;
}
bool continue_or_exit()
{

	string ch;
	cout << "  If this operation is not the one you want, enter 'E' to Exit, otherwise enter 'C' to Continue: ";
	while (true) {

		getline(cin, ch);
		if (ch == "e" || ch == "E")
		{
			system("CLS");
			TIME();
			return 0;

		}
		else if (ch == "c" || ch == "C")
		{
			system("CLS");
			TIME();
			return 1;
		}
		else
			cout << "  INVALID INPUT !\n";
	}
}
bool confirm()
{
	string ans;

	ans = char(input());
	if (ans == "y" || ans == "Y") return 1;
	else if (ans == "N" || ans == "n") return 0;
	else return confirm();

}
void view_prof(doc doctor[], int current_doc)
{
	cout << "  Profile info:" << endl;
	cout << "  ------------------------------------------------------" << endl;
	cout << "  Username:\t\t" << doctor[current_doc].user_name << endl;
	cout << "  Password:\t\t" << doctor[current_doc].password << endl;
	cout << "  Specialty:\t\t" << doctor[current_doc].specialty << endl;
	cout << "  Name:\t\t\t" << doctor[current_doc].first_name << " " << doctor[current_doc].last_name << endl;
	cout << "  Age:\t\t\t" << doctor[current_doc].age << endl;
	cout << "  Phone number:\t\t" << doctor[current_doc].phone_number << endl;
	cout << "  Years of experience:\t" << doctor[current_doc].years_of_experience << endl;
	cout << "  Price of session:\t" << doctor[current_doc].Fees << endl;
	cout << "  ------------------------------------------------------" << endl;
}
int string_to_int(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		num += ((s[i] - '0') * pow(10, s.size() - i - 1));
		// num*=10;
		// num+=s[i]-'0';
	}
	return num;
}
int input(int begin, int end)
{
	bool correct = true;
	int num;
	string s;
	getline(cin, s);
	if (s == "e" || s == "E")
	{
		cout << "  Before exiting..\n";
		cout << "  Do you want to rate us ? (y / n)\n";
		if (confirm())	Rate();
		exit(0);
	}
	// cout << s << endl;
	for (int i = 0; i < s.size(); i++)
	{
		correct = false;
		for (char j = '0'; j <= '9'; j++)
		{
			if (s.at(i) == j) correct = true;
		}
		if (!correct) break;
	}
	if (s.size() > 6) correct = false;
	if (correct)
	{
		num = string_to_int(s);
		if (num >= begin && num <= end)// || (begin == -1 && end == -1))
		{
			return num;
		}
	}
	if (s == "y" || s == "Y" || s == "n" || s == "N") return int(s.at(0)); //char(input());
	cout << "  Invalid input..\n";
	cout << "  Enter valid input : ";
	return input(begin, end);
}
bool duration_possible(int b_hour, int b_min, int e_hour, int e_min, int session[]) {

	int counter = 0;
	for (int i = 0; i < 4; i++)
	{
		if (((e_hour * 60 + e_min) - (b_hour * 60 + b_min)) % session[i] == 0)
		{
			counter++;
		}
	}

	if (counter == 0) {
		cout << "  The interval isn't compatibale with any of the duration options!! Please enter again." << endl; //    (15,30,45,60) minutes. 
		return 0;
	}

	return 1;

}
int display_duration(int session[], int b_hour, int b_min, int e_hour, int e_min)
{
	// int session[4]={15,30,45,60}; it moved to int main
	int counter = 0;
	int index[4] = { -1,-1,-1,-1 };
	cout << "  Choose the duration for your session (minutes) :\n";
	cout << "  -------------------------------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		if (((e_hour * 60 + e_min) - (b_hour * 60 + b_min)) % session[i] == 0)
		{
			index[counter] = i;

			cout << "  " << ++counter << ": " << session[i] << endl;
		}
	}

	cout << endl << "  Enter your choice: ";

	//cout << counter << endl;
	return (index[input(1, counter) - 1]);
}
void save_sessions(doc doctor[], int current_doc, int b_h, int b_m, int duration, int index)
{
	int total_begin_min = b_h * 60 + b_m;
	int total_end_min = total_begin_min + duration;

	for (int i = 0; i < doctor[current_doc].Work_Date[index].num_sessions; i++)
	{
		doctor[current_doc].Work_Date[index].All_Sessions[i].B_hour = total_begin_min / 60;
		doctor[current_doc].Work_Date[index].All_Sessions[i].B_min = total_begin_min % 60;

		doctor[current_doc].Work_Date[index].All_Sessions[i].E_hour = total_end_min / 60;
		doctor[current_doc].Work_Date[index].All_Sessions[i].E_min = total_end_min % 60;

		total_begin_min = total_end_min;
		total_end_min += duration;
	}
}
void choose_breaks(doc doctor[], int current_doc, int index, bool flag3)
{

	if (flag3 != 1) {
		cout << "  Do you want any breaks? (Y/N): ";
		if (!confirm()) return;
	}


	cout << "\n  Choose your breaks from these times :\n";
	cout << "  ----------------------------------------\n";

	for (int i = 0; i < doctor[current_doc].Work_Date[index].num_sessions; i++)
	{

		cout << "  " << setw(2) << setfill(' ') << i + 1 << ") From ";
		cout << setw(2) << doctor[current_doc].Work_Date[index].All_Sessions[i].B_hour << " : "
			<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[index].All_Sessions[i].B_min;
		cout << "   To ";
		cout << setw(2) << setfill(' ') << doctor[current_doc].Work_Date[index].All_Sessions[i].E_hour << " : "
			<< setw(2) << setfill('0') << doctor[current_doc].Work_Date[index].All_Sessions[i].E_min << '\n';

		doctor[current_doc].Work_Date[index].All_Sessions[i].breaks = 0;

	}
	int num_of_breaks;
	cout << "\n  How many breaks do you want? ";
	num_of_breaks = input(1, doctor[current_doc].Work_Date[index].num_sessions);

	while (num_of_breaks == doctor[current_doc].Work_Date[index].num_sessions && doctor[current_doc].Work_Date[index].num_sessions != 1) {

		cout << "  You cannot take the whole day as vacation,doctor!" << endl << endl;
		cout << "\n  How many breaks do you want? ";
		num_of_breaks = input(1, doctor[current_doc].Work_Date[index].num_sessions);
	}

	int break_index;

	for (int j = 0; j < num_of_breaks; j++)
	{
		cout << "  Enter your " << j + 1 << " choice: "; break_index = input(1, doctor[current_doc].Work_Date[index].num_sessions);
		doctor[current_doc].Work_Date[index].All_Sessions[break_index - 1].breaks = 1;
	}
}
void patient_cancelled(pat patient[], doc doctor[], int current_doc, Work_Dates a, int sess_index, int last_patient_array)
{
	// notify the patient that their appointment has been cancelled

	for (int i = 0; i < last_patient_array; i++)
	{
		for (int j = 0; j < patient[i].num_of_appointments_booked; j++)
		{

			if (a.All_Sessions[sess_index].B_hour == patient[i].appointments[j].booked[0].hour &&
				a.All_Sessions[sess_index].B_min == patient[i].appointments[j].booked[0].min &&
				patient[i].appointments[j].doc_username == doctor[current_doc].user_name
				&& patient[i].appointments[j].booked[0].booked == 1)
			{
				remove_7ogozat(patient, doctor, current_doc, i, j);
				patient[i].appointments[j].booked[0].booked = 0;  //change to zero

			}

		}
	}
}
void remove_7ogozat(pat patient[], doc doctor[], int current_doc, int patient_index, int patient_app)
{
	// delete from doc appointments then *** shift *** the appointments int the array

	for (int t = 0; t < doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED; t++)
	{

		if ((str_equal(patient[patient_index].appointments[patient_app].booked[0], doctor[current_doc].Appointments.booked[t])) &&
			patient[patient_index].appointments[patient_app].doc_username == doctor[current_doc].user_name) {

			for (int n = t; n < (doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED); n++)
			{
				if (n != doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED - 1)
				{
					doctor[current_doc].Appointments.booked[n] = doctor[current_doc].Appointments.booked[n + 1];
				}

				else doctor[current_doc].Appointments.booked[n] = {};

			}
			doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED--;

		}

	}

}
bool alarm_for_doc(pat patient[], doc doctor[], int current_doc, int last_patient_array, Work_Dates b_edit, int Case, int index)
{
	// check if there is a patient that booked in the time that is required to be changed,so to alarm the doctor.

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool patient_exist = 0;

	for (int j = 0; j < doctor[current_doc].Appointments.NUM_OF_APPOINTMENTS_BOOKED; j++)
	{

		if (doctor[current_doc].Appointments.booked[j].day_name == b_edit.day)
		{
			if (Case == 1 || Case == 2) //edit day and duration
			{
				patient_exist = 1;
				SetConsoleTextAttribute(h, 4);
				cout << "  There is a patient that booked this time.Do you wish to continue with the operation? (y/n): ";
				SetConsoleTextAttribute(h, 7);

				if (!confirm()) { return 0; }
				else
				{
					for (int i = 0; i < last_patient_array; i++)
					{
						for (int p = 0; p < patient[i].num_of_appointments_booked; p++)
						{
							if (b_edit.day == patient[i].appointments[p].booked[0].day_name &&
								patient[i].appointments[p].doc_username ==
								doctor[current_doc].user_name && patient[i].appointments[p].booked[0].booked == 1)
							{
								remove_7ogozat(patient, doctor, current_doc, i, p);
								patient[i].appointments[p].booked[0].booked = 0;  // tell the patient that the appointment is cancelled

							}
						}
					}
				}
			}
			else if (Case == 3) //edit breaks
			{
				bool flag = 0;
				for (int k = 0; k < b_edit.num_sessions; k++)
				{



					if (doctor[current_doc].Work_Date[index].All_Sessions[k].breaks == 1)
					{
						if (doctor[current_doc].Work_Date[index].All_Sessions[k].B_hour == doctor[current_doc].Appointments.booked[j].hour &&
							doctor[current_doc].Work_Date[index].All_Sessions[k].B_min == doctor[current_doc].Appointments.booked[j].min)
						{


							if (flag == 0)
							{
								//this flag to aviod printing this cout more than one time
								SetConsoleTextAttribute(h, 4);
								cout << "  There is a patient that booked this time.Do you wish to continue with this operation? (y/n): ";
								SetConsoleTextAttribute(h, 7);
								if (!confirm()) { return 0; }
								flag = 1;
							}

							patient_cancelled(patient, doctor, current_doc, doctor[current_doc].Work_Date[index], k, last_patient_array);
						}
					}
				}


			}
			else if (Case == 4)  //edit time interval
			{

				bool flag = 0;

				for (int i = 0; i < last_patient_array; i++)
				{
					for (int m = 0; m < patient[i].num_of_appointments_booked; m++)
					{

						bool work = 0;

						for (int k = 0; k < doctor[current_doc].Work_Date[index].num_sessions; k++)
						{


							if (doctor[current_doc].Work_Date[index].All_Sessions[k].B_hour ==
								patient[i].appointments[m].booked[0].hour &&
								doctor[current_doc].Work_Date[index].All_Sessions[k].B_min ==
								patient[i].appointments[m].booked[0].min && patient[i].appointments[m].doc_username ==
								doctor[current_doc].user_name)   //&& patient[i].appointments[m].booked[0].booked == 1
								work = 1;

							if (!work)
							{
								if (flag == 0)
								{
									SetConsoleTextAttribute(h, 4);
									cout << "  A patient will be affected.Do you wish to continue with the operation? (y/n): ";
									SetConsoleTextAttribute(h, 7);
									if (!confirm()) { return 0; }
									flag = 1;
								}

								remove_7ogozat(patient, doctor, current_doc, i, m);
								patient[i].appointments[m].booked[0].booked = 0;

							}

						}

					}


				}
			}

			break;
		}
	}

	return 1;
}
bool check_app_time(int b_h, int b_m, int e_h, int e_m) // check time is ordered correctly  
{
	if ((b_h == e_h && e_m > b_m) || (e_h > b_h)) return 1;
	else
	{
		cout << "  Invalide time!! Enter again.\n\n";
		return 0;
	}
}
int display_day(bool mode, doc doctor[], int current_doc)
{
	//mode = 1 if add
	//mode = 0 if edit and remove 

	int index[7] = { -1,-1,-1,-1,-1,-1,-1 };
	int counter = 0, day_choice;

	if (mode == 1) // display free days for add function.
	{
		cout << "  Choose from the avalible days: \n";
		cout << "  ---------------------------------\n\n";

		for (int i = 0; i < 7; i++)
		{
			if (doctor[current_doc].Work_Date[i].day == "ss")
			{
				cout << "  " << counter + 1 << "->" << days[i] << endl;
				index[counter] = i;
				counter++;
			}
		}


		if (counter == 1) cout << endl << "  Enter: ";
		else cout << endl << "  Enter from (1," << counter << ") : ";

		return index[input(1, counter) - 1];


	}
	else { // display working days for edit and remove functions 

		cout << "  Choose from your working days: \n";
		cout << "  ---------------------------------\n\n";

		for (int i = 0; i < 7; i++)
		{
			if (doctor[current_doc].Work_Date[i].day != "ss")
			{
				cout << "  " << counter + 1 << "->" << days[i] << endl;
				index[counter] = i;
				counter++;
			}
		}


		if (counter == 1) cout << endl << "  Enter: ";
		else cout << endl << "  Enter from (1," << counter << ") : ";

		return index[input(1, counter) - 1];
	}

}
bool str_equal(booking b1, booking b2) {

	if (b1.booked == b2.booked && b1.day == b2.day && b1.day_name == b2.day_name && b1.doc_speciality == b2.doc_speciality && b1.duration == b2.duration && b1.hour == b2.hour &&
		b1.min == b2.min && b1.month == b2.month && b1.patient_age == b2.patient_age && b1.patient_name == b2.patient_name &&
		b1.patient_user_name == b2.patient_user_name && b1.year == b2.year) return 1;
	else return 0;
}
/////////////////////////////////////////////////////////////////////////
void input_data(doc doctor[], pat patient[], int& last_doc_array, int& last_patient_array)
{

	fstream pati, doct;
	string s;
	pati.open("patient", ios::in);
	doct.open("doctor", ios::in);

	pati >> last_patient_array;
	doct >> last_doc_array;



	for (int m = 0; m < last_patient_array; m++)
	{

		pati >> patient[m].username;
		pati >> patient[m].password;
		pati >> patient[m].first_name;
		pati >> patient[m].last_name;
		pati >> patient[m].age;
		pati >> patient[m].ID;// index in array patient  
		pati >> patient[m].gender;
		pati >> patient[m].phone_number;

		pati >> patient[m].num_of_appointments_booked;


		for (int n = 0; n < patient[m].num_of_appointments_booked; n++) {


			pati >> patient[m].appointments[n].booked[0].day_name;
			pati >> patient[m].appointments[n].booked[0].day;
			pati >> patient[m].appointments[n].booked[0].month;
			pati >> patient[m].appointments[n].booked[0].year;
			pati >> patient[m].appointments[n].booked[0].hour;
			pati >> patient[m].appointments[n].booked[0].min;
			pati >> patient[m].appointments[n].booked[0].duration;
			pati >> patient[m].appointments[n].booked[0].doc_speciality;
			pati >> patient[m].appointments[n].booked[0].patient_name;
			pati >> patient[m].appointments[n].booked[0].patient_user_name;
			pati >> patient[m].appointments[n].booked[0].patient_age;
			pati >> patient[m].appointments[n].booked[0].booked;
			pati >> patient[m].appointments[n].doctor_name;
			pati >> patient[m].appointments[n].doc_username;

		}

		pati >> patient[m].history_list_size;

		for (int n = 0; n < patient[m].history_list_size; n++) {


			pati >> patient[m].history[n].booked[0].day_name;
			pati >> patient[m].history[n].booked[0].day;
			pati >> patient[m].history[n].booked[0].month;
			pati >> patient[m].history[n].booked[0].year;
			pati >> patient[m].history[n].booked[0].hour;
			pati >> patient[m].history[n].booked[0].min;
			pati >> patient[m].history[n].booked[0].duration;
			pati >> patient[m].history[n].booked[0].doc_speciality;
			pati >> patient[m].history[n].booked[0].patient_name;
			pati >> patient[m].history[n].booked[0].patient_user_name;
			pati >> patient[m].history[n].booked[0].patient_age;
			pati >> patient[m].history[n].booked[0].booked;
			pati >> patient[m].history[n].doctor_name;
			pati >> patient[m].history[n].doc_username;

		}
	}

	for (int i = 0; i < last_doc_array; i++)
	{
		doct >> doctor[i].user_name;
		doct >> doctor[i].password;
		doct >> doctor[i].specialty;
		doct >> doctor[i].first_name;
		doct >> doctor[i].last_name;
		doct >> doctor[i].age;
		doct >> doctor[i].Fees;
		doct >> doctor[i].phone_number;
		doct >> doctor[i].years_of_experience;
		doct >> doctor[i].ID;
		doct >> doctor[i].gender;
		doct >> doctor[i].day_name;


		doct >> doctor[i].num_of_days;
		for (int k = 0; k < 7; k++)
		{

			doct >> doctor[i].Work_Date[k].day;
			doct >> doctor[i].Work_Date[k].B_hour;
			doct >> doctor[i].Work_Date[k].B_min;
			doct >> doctor[i].Work_Date[k].E_hour;
			doct >> doctor[i].Work_Date[k].E_min;
			doct >> doctor[i].Work_Date[k].duration;
			doct >> doctor[i].Work_Date[k].num_sessions;

			for (int h = 0; h < doctor[i].Work_Date[k].num_sessions; h++)
			{
				doct >> doctor[i].Work_Date[k].All_Sessions[h].B_hour;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].B_min;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].E_hour;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].E_min;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].breaks;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].booked;
				doct >> doctor[i].Work_Date[k].All_Sessions[h].number;
			}


		}

		doct >> doctor[i].Appointments.NUM_OF_APPOINTMENTS_BOOKED;

		for (int l = 0; l < doctor[i].Appointments.NUM_OF_APPOINTMENTS_BOOKED; l++)
		{

			doct >> doctor[i].Appointments.booked[l].day_name;
			doct >> doctor[i].Appointments.booked[l].day;
			doct >> doctor[i].Appointments.booked[l].month;
			doct >> doctor[i].Appointments.booked[l].year;
			doct >> doctor[i].Appointments.booked[l].hour;
			doct >> doctor[i].Appointments.booked[l].min;
			doct >> doctor[i].Appointments.booked[l].duration;
			doct >> doctor[i].Appointments.booked[l].doc_speciality;
			doct >> doctor[i].Appointments.booked[l].patient_name;
			doct >> doctor[i].Appointments.booked[l].patient_user_name;
			doct >> doctor[i].Appointments.booked[l].patient_age;
			doct >> doctor[i].Appointments.booked[l].booked;

		}
		doct >> doctor[i].Appointments.doctor_name;  // his own name
		doct >> doctor[i].Appointments.doc_username; // his own username


		doct >> (doctor[i].num_of_patients);

		for (int r = 0; r < (doctor[i].num_of_patients); r++)
		{
			doct >> doctor[i].rate[r];
		}

		doct >> doctor[i].avg_rates;
		doct >> doctor[i].count_of_rates;
		doct >> doctor[i].searching_times;

	}

	pati.close();
	doct.close();


}
//done
void save_data(doc doctor[], pat patient[], int last_doc_array, int last_patient_array)
{

	fstream pati, doct;

	pati.open("patient", ios::out);
	doct.open("doctor", ios::out);

	pati << last_patient_array << endl;
	doct << last_doc_array << endl;

	for (int m = 0; m < last_patient_array; m++)
	{

		pati << patient[m].username << endl;
		pati << patient[m].password << endl;
		pati << patient[m].first_name << endl;
		pati << patient[m].last_name << endl;
		pati << patient[m].age << endl;
		pati << patient[m].ID << endl;// index in array patient  
		pati << patient[m].gender << endl;
		pati << patient[m].phone_number << endl;

		pati << patient[m].num_of_appointments_booked << endl;


		for (int n = 0; n < patient[m].num_of_appointments_booked; n++) {


			pati << patient[m].appointments[n].booked[0].day_name << endl;
			pati << patient[m].appointments[n].booked[0].day << endl;
			pati << patient[m].appointments[n].booked[0].month << endl;
			pati << patient[m].appointments[n].booked[0].year << endl;
			pati << patient[m].appointments[n].booked[0].hour << endl;
			pati << patient[m].appointments[n].booked[0].min << endl;
			pati << patient[m].appointments[n].booked[0].duration << endl;


			pati << patient[m].appointments[n].booked[0].doc_speciality << endl;
			pati << patient[m].appointments[n].booked[0].patient_name << endl;
			pati << patient[m].appointments[n].booked[0].patient_user_name << endl;
			pati << patient[m].appointments[n].booked[0].patient_age << endl;

			pati << patient[m].appointments[n].booked[0].booked << endl;
			pati << patient[m].appointments[n].doctor_name << endl;
			pati << patient[m].appointments[n].doc_username << endl;

		}

		pati << patient[m].history_list_size << endl;

		for (int n = 0; n < patient[m].history_list_size; n++) {


			pati << patient[m].history[n].booked[0].day_name << endl;
			pati << patient[m].history[n].booked[0].day << endl;
			pati << patient[m].history[n].booked[0].month << endl;
			pati << patient[m].history[n].booked[0].year << endl;
			pati << patient[m].history[n].booked[0].hour << endl;
			pati << patient[m].history[n].booked[0].min << endl;
			pati << patient[m].history[n].booked[0].duration << endl;
			pati << patient[m].history[n].booked[0].doc_speciality << endl;
			pati << patient[m].history[n].booked[0].patient_name << endl;
			pati << patient[m].history[n].booked[0].patient_user_name << endl;
			pati << patient[m].history[n].booked[0].patient_age << endl;
			pati << patient[m].history[n].booked[0].booked << endl;
			pati << patient[m].history[n].doctor_name << endl;
			pati << patient[m].history[n].doc_username << endl;

		}
	}

	for (int i = 0; i < last_doc_array; i++)
	{
		doct << doctor[i].user_name << endl;
		doct << doctor[i].password << endl;
		doct << doctor[i].specialty << endl;
		doct << doctor[i].first_name << endl;
		doct << doctor[i].last_name << endl;
		doct << doctor[i].age << endl;
		doct << doctor[i].Fees << endl;
		doct << doctor[i].phone_number << endl;
		doct << doctor[i].years_of_experience << endl;
		doct << doctor[i].ID << endl;
		doct << doctor[i].gender << endl;
		doct << doctor[i].day_name << endl;


		doct << doctor[i].num_of_days << endl;
		for (int k = 0; k < 7; k++)
		{

			doct << doctor[i].Work_Date[k].day << endl;
			doct << doctor[i].Work_Date[k].B_hour << endl;
			doct << doctor[i].Work_Date[k].B_min << endl;
			doct << doctor[i].Work_Date[k].E_hour << endl;
			doct << doctor[i].Work_Date[k].E_min << endl;
			doct << doctor[i].Work_Date[k].duration << endl;
			doct << doctor[i].Work_Date[k].num_sessions << endl;

			for (int h = 0; h < doctor[i].Work_Date[k].num_sessions; h++)
			{
				doct << doctor[i].Work_Date[k].All_Sessions[h].B_hour << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].B_min << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].E_hour << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].E_min << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].breaks << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].booked << endl;
				doct << doctor[i].Work_Date[k].All_Sessions[h].number << endl;
			}


		}

		doct << doctor[i].Appointments.NUM_OF_APPOINTMENTS_BOOKED << endl;

		for (int l = 0; l < doctor[i].Appointments.NUM_OF_APPOINTMENTS_BOOKED; l++)
		{

			doct << doctor[i].Appointments.booked[l].day_name << endl;
			doct << doctor[i].Appointments.booked[l].day << endl;
			doct << doctor[i].Appointments.booked[l].month << endl;
			doct << doctor[i].Appointments.booked[l].year << endl;
			doct << doctor[i].Appointments.booked[l].hour << endl;
			doct << doctor[i].Appointments.booked[l].min << endl;
			doct << doctor[i].Appointments.booked[l].duration << endl;
			doct << doctor[i].Appointments.booked[l].doc_speciality << endl;
			doct << doctor[i].Appointments.booked[l].patient_name << endl;
			doct << doctor[i].Appointments.booked[l].patient_user_name << endl;
			doct << doctor[i].Appointments.booked[l].patient_age << endl;
			doct << doctor[i].Appointments.booked[l].booked << endl;

		}
		doct << doctor[i].Appointments.doctor_name << endl;  // his own name
		doct << doctor[i].Appointments.doc_username << endl; // his own username

		doct << (doctor[i].num_of_patients) << endl;

		for (int r = 0; r < (doctor[i].num_of_patients); r++)
		{
			doct << doctor[i].rate[r] << endl;
		}
		doct << doctor[i].avg_rates << endl;
		doct << doctor[i].count_of_rates << endl;
		doct << doctor[i].searching_times << endl;
	}

	pati.close();
	doct.close();
}