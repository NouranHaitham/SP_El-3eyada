#pragma once

int Agmad_Function_Fel_System(doc doctor[], int last_doc_array)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int index = 0, doctors_count = 0;
    char ch = '\0';
    int doc_index = 0;
    int max_chars = 0, char_count = 0, max_doc_index = -1, max_rate = 0;
    int searching_times = 0;
    bool found = false;

    string doc_username = "\0";
    cout << "\n\n  Enter the doctor's username : ";
    while (true)
    {
        ch = _getch();
        if (ch == '\r')
        {
            if (doc_username == "\0") continue;
            else if (found)
            {
                if (doctors_count == 1) return doc_index;
                else                                           //if (doctors_count >1)
                {
                    cout << "\b ";
                    index--;
                    SetConsoleTextAttribute(h, 4);
                    cout << "\n\t\t\t\t( More than one doctor !!!  complete the username! )\t\t";
                    SetConsoleTextAttribute(h, 7);
                    continue;
                }
            }
            else if (!found)
            {
                if (max_chars == 0 || ((doc_username.size() > doctor[doc_index].user_name.size() && (doc_username.size() - max_chars) * 2 > doctor[doc_index].user_name.size())
                    || (doc_username.size() <= doctor[doc_index].user_name.size() && max_chars * 2 < doctor[doc_index].user_name.size())))
                {
                    cout << "No username found\n";
                    Sleep(500 + rand() % 3500);
                    return -1;
                }

                SetConsoleTextAttribute(h, 4);
                cout << "\n\n\t\t\t      Did you mean : ";
                SetConsoleTextAttribute(h, 7);
                cout << doctor[doc_index].user_name << "\t\t\n";
                cout << "\n\n\t\t\t      ";
                if (!confirm())  doc_index = -1;
                return doc_index;
            }
        }
        else if (ch == '\b')
        {
            if (doc_username == "\0")continue;
            else if (index >= 1)
            {
                doc_username.pop_back();
                cout << "\b\b";
                index--;
            }
        }
        else if (ch != ' ') doc_username += ch;
        system("CLS");
        cout << "\n\n  Enter the doctor's username : ";
        cout << doc_username << "\n\n";
        doctors_count = 0;
        found = false;
        max_chars = 0, max_rate = 0, searching_times = 0;
        for (int i = 0; i < last_doc_array; i++)
        {
            char_count = 0;
            for (int j = 0; j < doc_username.size() && j < doctor[i].user_name.size(); j++)
            {
                if (doctor[i].user_name[j] == doc_username[j])
                {
                    char_count++;
                }
            }
            if (!doc_username.empty() && char_count == doc_username.size())
            {
                found = true;
                cout << "\t\t\t      " << doctor[i].user_name << "\t\t\n", doctors_count++;
                doc_index = i;
            }
            if (char_count > max_chars)
            {
                doc_index = i;
                max_chars = char_count;
            }
            else if (char_count == max_chars)
            {
                if (doctor[i].searching_times > searching_times) doc_index = i, searching_times = doctor[i].searching_times;
                else if (doctor[i].searching_times == searching_times && doctor[i].avg_rates > max_rate)
                    doc_index = i, max_rate = doctor[i].avg_rates;
            }
        }

        index++;
    }

    if (index < doc_username.size() && index >0) doc_username.erase(index); // to check if index in range,if not,there will be error
    else if (index == 0) doc_username.clear(); // if index 0,that means user backspaced everything,so clear string.


}

bool Patient_Modes(pat patient[], int current_patient, doc doctor[], doc suitable_doctor[], int last_doc_array)
{
    int* DOC_NUM = new int(0);
    appointment SUITALE_DATE;
    int Case, choice;
    bool* found = new bool(0);
    string answer;
    bool wrong_input = false;

    Case = input(1, 9);
    //if (Case == 0) { EXIT = 0; return 0; }
    do {
        if (Case == 0)
        {
            Patient_Homepage(patient, current_patient);
            Case = input(1, 9);
        }
        switch (Case) {
        case 1:            // book an appointment
            system("CLS");
            if (book_an_appointment(DOC_NUM, SUITALE_DATE, patient, suitable_doctor, doctor, current_patient, last_doc_array))
            {
                cout << "\n  1. Book another appointment\n\n";
                cout << "  2. View your appointments\n\n";
                cout << "  3. Homepage\n\n";
                cout << "  4. Exit\n\n";
                choice = input(1, 4);
                if (choice == 1)
                {
                    system("CLS");
                    Case = 1;
                }
                else if (choice == 2)
                {
                    view_appointments(patient, current_patient);
                    cout << "\n";
                    cout << "  1. Homepage\n\n";
                    cout << "  2. Exit\n\n";
                    choice = input(1, 2);
                    if (choice == 1) Case = 0;
                    else if (choice == 2) return false;
                }
                else if (choice == 3) Case = 0;
                else if (choice == 4) return false;
            }
            else Case = 0;
            break;
        case 2:
            Case = 0;
            search_doctor_by_username(DOC_NUM, SUITALE_DATE, patient, suitable_doctor, doctor, current_patient, last_doc_array);
            system("CLS");
            cout << "\n  1. Search another doctor by name \n\n";
            cout << "  2. Homepage\n\n";
            cout << "  3. Exit\n\n";
            switch (input(1, 3))
            {
            case 1: Case = 2;
                break;
            case 2: Case = 0;
                break;

            case 3: return false;
            }

            //exit
            break;
        case 3: // edit_app
            system("CLS");
            if (view_appointments(patient, current_patient))
            {
                cout << "  Do you want to edit ? ( y / n )\n  ";
                if (confirm()) edit_appointment(DOC_NUM, SUITALE_DATE, patient, suitable_doctor, doctor, current_patient, last_doc_array);
            }
            cout << "  1. Homepage\n\n";
            cout << "  2. Exit\n\n";
            choice = input(1, 2);
            if (choice == 1) Case = 0;
            else if (choice == 2) return false;
            break;
        case 4:  //delete_app
            system("CLS");
            if (view_appointments(patient, current_patient))
                delete_appointment(patient, current_patient, doctor, last_doc_array);
            cout << "  1. Delete another appointment\n\n";
            cout << "  2. View your current appointments\n\n";
            cout << "  3. Homepage\n\n";
            cout << "  4. Exit\n\n";
            choice = input(1, 4);
            if (choice == 1) Case = 4;
            else if (choice == 2)
            {
                view_appointments(patient, current_patient);
                cout << "\n";
                cout << "  1. Homepage\n\n";
                cout << "  2. Exit\n\n";
                choice = input(1, 2);
                if (choice == 1) Case = 0;
                else if (choice == 2) return false;
            }
            else if (choice == 3) Case = 0;
            else if (choice == 4) return false;
            break;
        case 5:  //clear_history
            system("CLS");
            if (patient[current_patient].history_list_size != 0)
            {
                cout << "\n  Do you want to view your history list first ? \n";
                if (confirm())  history_list_display(patient, current_patient);
                cout << "\n  clear history ?(y/n)";
                if (confirm()) clear_history(patient, current_patient);
            }
            else cout << "\n  << There is no history to clear >>\n\n";

            cout << "  1. Homepage\n\n";
            cout << "  2. Exit\n\n";
            choice = input(1, 2);
            if (choice == 1) Case = 0;
            else if (choice == 2) return false;
            break;
        case 6:  //edit_info
            system("CLS");
            Edit_patient_info(patient, current_patient, doctor);
            cout << "  1. Homepage\n\n";
            cout << "  2. Exit\n\n";
            choice = input(1, 2);
            if (choice == 1) Case = 0;
            else if (choice == 2) return false;
            break;
        case 7:  // rate
            system("CLS");
            Rate();
            cout << "  1. Homepage\n\n";
            cout << "  2. Exit\n\n";
            choice = input(1, 2);
            if (choice == 1) Case = 0;
            else if (choice == 2) return false;
            break;
        case 8: // logout
            system("CLS");
            cout << "  It's okay, we wanna do it from the beginning :), bye.\n  ";
            return true;

        case 9:
            system("CLS");
            return false;
        }
    } while (Case == 1 || Case == 2 || Case == 0);

}
bool view_appointments(pat patient[], int current_patient)
{
    int flag = 1;
    bool exist = false;
    if (patient[current_patient].num_of_appointments_booked) exist = true;
    else cout << "              !!! You do not have any appointments !!!\n\n";
    if (exist)
    {
        cout << "  ---------------------------------------------------------------------------------------------------------------------\n";
        cout << "  No.|   Day    |     Date      | Start time | Duration |         Speciality         |  Doctor's name - username \n";
        cout << "  ---------------------------------------------------------------------------------------------------------------------\n\n";

        for (int A = 0; A < patient[current_patient].num_of_appointments_booked; A++)
        {
            if (!patient[current_patient].appointments[A].booked[0].booked) flag = 2;

            if (flag == 1) cout << "  " << left << setw(3) << setfill(' ') << A + 1 << "| ";
            else
            {
                cout << "  This appointment has been cancelled from the doctor. Details:\n";
                cout << "  " << setw(3) << setfill(' ') << "| ";
            }

            cout << left << setw(9) << patient[current_patient].appointments[A].booked[0].day_name << "|"
                << setw(2) << setfill(' ') << patient[current_patient].appointments[A].booked[0].day << " / "
                << setw(2) << setfill(' ') << patient[current_patient].appointments[A].booked[0].month << " / "
                << patient[current_patient].appointments[A].booked[0].year << " |    "
                << setw(2) << setfill(' ') << patient[current_patient].appointments[A].booked[0].hour << ":"
                << setw(2) << setfill(' ') << patient[current_patient].appointments[A].booked[0].min << "    |    "
                << patient[current_patient].appointments[A].booked[0].duration << "    | "
                << left << setw(25) << patient[current_patient].appointments[A].booked[0].doc_speciality << " | "
                << patient[current_patient].appointments[A].doctor_name << " - " << patient[current_patient].appointments[A].doc_username << "\n";

            cout << "  ------------------------------------------------------------------------------------------------------\n";
            //delete cancelled appointment
            if (flag == 2)
            {
                for (int h = A; h < patient[current_patient].num_of_appointments_booked; h++)
                {
                    if (h != patient[current_patient].num_of_appointments_booked - 1)
                    {
                        patient[current_patient].appointments[h] = patient[current_patient].appointments[h + 1];
                    }
                    else  patient[current_patient].appointments[h] = {};
                }
                A--;
            }
        }
    }
    return exist;
}
void delete_appointment(pat patient[], int current_patient, doc doctor[], int last_doc_array, int num, bool history) //current patient
{
    int choice;

    if (num == -1)
    {
        cout << "  1. Delete certain appointment\n  2. Delete all\n\n  choice: ";
        choice = input(1, 2);
        if (choice == 1)
        {
            cout << "  The number of appointment you want to delete : ";
            num = input(1, patient[current_patient].num_of_appointments_booked); //num is number of app during view function , num-1 is index
        }
        else num = 0; //terminate dafault value
    }

    if (num > 0) // delete certain appointment
    {
        for (int i = 0; i < last_doc_array; i++)
        {
            if (doctor[i].user_name == patient[current_patient].appointments[num - 1].doc_username)
            {
                remove_7ogozat(patient, doctor, i, current_patient, num - 1);
                break;
            }
        }

        for (int j = num - 1; j < patient[current_patient].num_of_appointments_booked; j++)
        {
            if (j != patient[current_patient].num_of_appointments_booked - 1)
            {
                patient[current_patient].appointments[j] = patient[current_patient].appointments[j + 1];
            }
            else  patient[current_patient].appointments[j] = {};
        }
        patient[current_patient].num_of_appointments_booked--;
        if (!history) cout << "\n   The appointment has been deleted successfully! \n";
        ///////// here , certain appointment is deleted
    }

    if (num == 0) //delete all 
    {
        for (int l = 0; l < patient[current_patient].num_of_appointments_booked; l++)
        {
            for (int i = 0; i < last_doc_array; i++)
            {
                if (doctor[i].user_name == patient[current_patient].appointments[l].doc_username)
                {
                    remove_7ogozat(patient, doctor, i, current_patient, l);
                    break;
                }
            }
            patient[current_patient].appointments[l] = {}; //delete all bedoon root > <
        }
        patient[current_patient].num_of_appointments_booked = 0;
        cout << "\n   All appointments have been deleted successfully! \n";
    }
}
void patient_profile(pat patient[], int current_patient)
{

    cout << endl << endl;
    cout << "  You current info:" << endl;
    cout << "  -------------------" << endl;
    cout << "  ->Name:     " << patient[current_patient].first_name << " " << patient[current_patient].last_name << endl;
    cout << "  ->Username: " << patient[current_patient].username << endl;
    cout << "  ->Password: " << patient[current_patient].password << endl;
    cout << "  ->Age:      " << patient[current_patient].age << endl;


}
void Edit_patient_info(pat patient[], int current_patient, doc doctor[])
{
    string newusername, new_first_name, new_last_name;
    string oldpassword, currentpassword, newpassword, confirmationpassword;
    int newage;
    patient_profile(patient, current_patient);
    char confirmation_Answer;
    char continue_answer = '\0', display_answer;
    cout << "1.change info\n2.homepage\n";
    int answer = input(1, 2);
    if (answer == 2)
    {
        cout << "\n  Now you will be directed to the main menu! Thank you\n";
        system("CLS");
        return; //go to home page
    }
    cout << "\n  1.name\n"
        << "  2.username\n"
        << "  3.password\n"
        << "  4.age\n";
    cout << "\n  What do you want to change? Enter number : 1 / 2 / 3 / 4 .\n" << endl;
    do {
        continue_answer = 'n';

        switch (input(1, 4))
        {
        case 1:
            cout << "  Enter: \n  first name: ";
            cin >> new_first_name;
            cout << "\n  last name: ";
            cin >> new_last_name;
            cout << "\n  Do you want to confirm?(y/n)\n";
            if (confirm()) {
                patient[current_patient].first_name = new_first_name;
                patient[current_patient].last_name = new_last_name;
                cout << "  Changes saved! ";
            }
            break;
        case 2:
            cout << "  Enter the new username: ";
            newusername = cin_username(doctor, patient);
            cout << "\n  Do you want to confirm?(y/n)\n";
            if (confirm()) {
                patient[current_patient].username = newusername;
                cout << "\n  Changes saved! \n";
            }
            break;
        case 3:
            oldpassword = patient[current_patient].password;
            cout << "\n  Enter your current password: ";
            currentpassword = cin_password();
            cout << " Enter your new password: ";
            newpassword = cin_password();
            cout << "\n  Confirm your new password: ";
            confirmationpassword = cin_password();
            cout << endl;
            if ((currentpassword == oldpassword) &&
                (confirmationpassword == newpassword)) {
                patient[current_patient].password = newpassword;
                cout << "\n  Changes saved! \n";
            }
            else cout << "\n  Sorry, something went wrong!\n";
            break;
        case 4:
            cout << "\n  Enter your new age: \n";
            newage = input(1, 100);
            cout << "  Do you want to confirm?(y/n)";
            if (confirm()) {
                patient[current_patient].age = newage;
                cout << "\n  Changes saved!\n";
            }
            break;
        }

        cout << "  Do you want to change another info?(y/n)";
        if (confirm()) continue_answer = 'y';
        if (continue_answer == 'y') {
            cout << "\n  Enter number from 1 to 4 : ";
        }
    } while (continue_answer == 'y');

    cout << "  Do you want to display your info?(y/n)\n  ";

    if (confirm()) {

        patient_profile(patient, current_patient);
    }
    cout << "  You will be directed to your homepage now." << '\n';
}
void Patient_Homepage(pat patient[], int current_patient)
{
    system("CLS");
    // HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n                                                                                                                                       [x] \n\n";
    cout << "\n\n                                        Hello "; cout << patient[current_patient].first_name << endl;
    cout << "                                       --------------  "; //cout << patient[current_patient].;
    cout << "\n\n";
    cout << "       ------------------------------\t\t\t------------------------------";
    cout << "\n       |     Book an appointment    |\t\t\t|  search doctor by username |";
    cout << "\n       |             1              |\t\t\t|             2              |";
    cout << "\n       ------------------------------\t\t\t------------------------------";
    cout << "\n";
    cout << "       ------------------------------\t\t\t------------------------------";
    cout << "\n       |  View and Edit appointments|\t\t\t|  Delete an appointment     |";
    cout << "\n       |             3              |\t\t\t|             4              |";
    cout << "\n       ------------------------------\t\t\t------------------------------";
    cout << "\n";
    cout << "       ------------------------------\t\t\t------------------------------";
    cout << "\n       |       Clear history        |\t\t\t|      Edit Your info        |";
    cout << "\n       |             5              |\t\t\t|             6              |";
    cout << "\n       ------------------------------\t\t\t------------------------------";
    cout << "\n";
    cout << "       ------------------------------\t\t\t\n";
    cout << "\n       |           Rate Us          |\t\t\t\n";
    cout << "\n       |             7              |\t\t\t\n";
    cout << "\n       ------------------------------\t\t\t\n\n";
    cout << "\n\n";
    cout << "       8. Log out \n\n       9. Exit \n\n  ";
}
void Suitable_Doctors_by_speciality(int* doc_num, int last_doc_array, doc suitable_doctor[], doc doctor[], string Specialty)
{
    *doc_num = 0;
    if (Specialty == "\0") Specialty = Specialty_Display();
    for (int i = 0; i < last_doc_array; i++)
    {
        if (doctor[i].specialty == Specialty)
        {
            suitable_doctor[*doc_num] = doctor[i];
            ++* doc_num;
        }
    }
}
bool Suitable_Doctors_by_day_name(int* doc_num, doc suitable_doctor[], string* day_name)
{
    bool found = false;
    int new_doc_num = 0;

    for (int i = 0; i < *doc_num; i++)
    {
        if (suitable_doctor[i].Work_Date[dayy(*day_name) - 1].day == *day_name)
        {
            suitable_doctor[new_doc_num++] = suitable_doctor[i];
            found = true;
        }
    }
    if (found)
    {
        *doc_num = new_doc_num;
        return true;
    }
    cout << "  " << *day_name << " is busy..\n\n";
    cout << "  1. Search for another day\n  ";
    cout << "  2. Homepage\n  ";
    if (input(1, 2) == 2) return false;
    *day_name = day_Display();
    return Suitable_Doctors_by_day_name(doc_num, suitable_doctor, day_name);
}
void input_date(appointment& Suitable_Date, string* day_name)
{
    // 0 -> year , 1 -> month , 2 -> day
    cout << "  Enter the suitable year : "; Suitable_Date.booked[0].year = input(2023, 2028);
    cout << "  Enter the suitable month : ";
    if (Suitable_Date.booked[0].year == (1900 + tmp->tm_year))
    {
        Suitable_Date.booked[0].month = input(tmp->tm_mon + 1, 12);
        cout << "  Enter the suitable day : ";
        if (Suitable_Date.booked[0].month == tmp->tm_mon + 1)
            Suitable_Date.booked[0].day = input(tmp->tm_mday, month_value[tmp->tm_mon]);
        else
            Suitable_Date.booked[0].day = input(1, month_value[tmp->tm_mon]);
    }
    else
    {
        Suitable_Date.booked[0].month = input(1, 12);
        cout << "  Enter the suitable day : ";
        Suitable_Date.booked[0].day = input(1, month_value[tmp->tm_mon]);
    }
    *day_name = calender_date(Suitable_Date.booked[0].day, Suitable_Date.booked[0].month, Suitable_Date.booked[0].year);
    /// *day_num;


}
void choose_by_date(int i, doc suitable_doctor[], string* day_name, appointment& suitable_date, int* index, bool& search_for_another_time)
{
    //cout << suitable_date.booked[0].day << " / " << suitable_date.booked[0].month << " / " << suitable_date.booked[0].year << endl;
    //cout << *day_name << "\n";
    int* sessions_number = new int(0);
    if (Search_For_Doctors(i, suitable_doctor, day_name, suitable_date.booked[i].day,
        suitable_date.booked[i].month, suitable_date.booked[i].year))
    {
        search_for_another_time = false;
        suitable_doctor[i].number = (++ * index);
        cout << "  ___________________________________________________________________\n\n";
        cout << "   " << suitable_doctor[i].number;
        View_Doctor_info(suitable_doctor, i);
        cout << "         |  First available time :  ";
        cout << "  [ " << suitable_date.booked[i].day << " / " << suitable_date.booked[i].month << " / "
            << suitable_date.booked[i].year << "]" << "\t" << "< " << *day_name << " > |" << endl;
        suitable_doctor[i].day_name = *day_name;
        cout << "         ------------------------------------------------------------\n";
        Show_Available_Time(i, suitable_doctor, day_name, sessions_number, 1, 0, suitable_date, 0);
        cout << " \n";
    }
}
void choose_by_day(int i, doc suitable_doctor[], string* day_name, appointment& suitable_date, int* index, bool& search_for_another_time)
{
    int count = 0, w__day = tmp->tm_wday + 2;
    time_t t = time(0);
    tm* tmp = localtime(&t);
    suitable_date.booked[i].day = tmp->tm_mday;
    suitable_date.booked[i].month = tmp->tm_mon + 1;
    suitable_date.booked[i].year = tmp->tm_year + 1900;
    search_for_another_time = true;
    calender_date(day_name, suitable_date.booked[i].day, suitable_date.booked[i].month, suitable_date.booked[i].year, w__day);
    while (true)
    {
        choose_by_date(i, suitable_doctor, day_name, suitable_date, index, search_for_another_time);
        if (search_for_another_time)
        {
            suitable_date.booked[i].day += 7;
            if (suitable_date.booked[i].day > month_value[suitable_date.booked[i].month - 1])
            {
                suitable_date.booked[i].day %= month_value[suitable_date.booked[i].month];
                suitable_date.booked[i].month++;
                if (suitable_date.booked[i].month > 12)
                {
                    suitable_date.booked[i].month %= 12;
                    suitable_date.booked[i].year++;
                }
            }
        }

        else break;
    }
}
void choose_by_certain_time(int i, int doc_num, appointment& suitable_date, doc suitable_doctor[], int way_number, bool& search_for_another_time, string* day_name, int* index)
{
    switch (way_number)
    {
    case 1:
        //input date ( date is constant ) le kol i ( menf34 ndkhal da gwa choose by date l2nana bnst3mlha fe choose by date ) w date m4 byb2a constant ..el date byge men choose by day el while  
        choose_by_date(i, suitable_doctor, day_name, suitable_date, index, search_for_another_time);
        break;
    case 2:
        choose_by_day(i, suitable_doctor, day_name, suitable_date, index, search_for_another_time);
        break;
    }
}
void profile(doc doctor[], int i)
{
    system("CLS");
    int num = 1;
    cout << "\t\t\t\t ---------------------------------------------------------------------------------------\t\t\n";
    cout << "\t\t\t\t |                                                                                      |\t\t\n";
    cout << "\t\t\t\t |        ------------------------------------------------                              |\t\t\n";
    cout << "\t\t\t\t |       |   Dr.                                          |                             |\t\t\n";
    cout << "\t\t\t\t |        ------------------------------------------------                              |\t\t\n";
    cout << "\t\t\t\t |        >> Speciality :                                                               |\t\t\n";
    cout << "\t\t\t\t |                      (years of experience)                                           |\t\t\n";
    cout << "\t\t\t\t |                       Overall Rating from       visitors                             |\t\t\n";
    cout << "\t\t\t\t |        Fees:       EGP                                                               |\t\t\n";
    cout << "\t\t\t\t |                                                                                      |\t\t\n";
    cout << "\t\t\t\t |        Working days:                                                                 |\t\t";

    cin_position(50, 3);

    cout << doctor[i].first_name << " " << doctor[i].last_name;
    cin_position(58, 5);
    cout << doctor[i].specialty;
    cin_position(52, 6);
    cout << doctor[i].years_of_experience;
    cin_position(46, 7);
    RATING(doctor[i].avg_rates);
    cin_position(78, 7);
    cout << doctor[i].count_of_rates;
    cin_position(48, 8);
    cout << doctor[i].Fees;

    for (int j = 0; j < 7; j++)
    {
        if (doctor[i].Work_Date[j].day != "ss" && doctor[i].Work_Date[j].day != "\0")
        {


            cin_position(58, 9 + num);
            cout << num++ << ". " << doctor[i].Work_Date[j].day;
            cin_position(33, 9 + num);
            cout << "|                                                                                      |\t\t\n";
        }
    }
    cout << "\t\t\t\t |                                                                                      |\t\t\n"
        << "\t\t\t\t  ------------------------------------------------------------------------------------- \t\t\n";
    //  << num++ << " . " << setw(9) << setfill(' ') << doctor[i].Work_Date[j].day

}
void search_doctor_by_username(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array)
{
    int current_doctor;
    bool Found = true, search_doc_by_name = false;
    system("CLS");
    //cout << "\n\n  Enter doctor's username : ";
    current_doctor = Agmad_Function_Fel_System(doctor, last_doc_array);
    if (current_doctor != -1)
    {
        system("CLS");
        profile(doctor, current_doctor);
        cout << "  1. Book appointment with \n\n";
        cout << "  2. back\n\n";
        switch (input(1, 2))
        {
        case 1:
            suitable_doctor[0] = doctor[current_doctor];
            *DOC_NUM = 1;
            search_doc_by_name = true;
            book_an_appointment(DOC_NUM, SUITALE_DATE, patient, suitable_doctor, doctor, current_patient, last_doc_array, search_doc_by_name);
            break;
        case 2: break;
        }
    }

}
void view_suitable_doctor(int i, doc suitable_doctor[], string* day_name, int* index, int& w__day, appointment& suitable_date, int j) // j is for search by name = num_sessions
{
    Search_Doc_For_Day(i, suitable_doctor, day_name, w__day, suitable_date); //first_suitable_date  / search_doc_for_day
    //suitable_doctor[i].number = i++;
    cout << "  ___________________________________________________________________\n\n";
    cout << "  " << i + 1;
    suitable_doctor[i].number = i + 1;
    View_Doctor_info(suitable_doctor, i);
    cout << "         |  First available time :  ";
    cout << "  [ " << suitable_date.booked[i].day << " / " << suitable_date.booked[i].month << " / "
        << suitable_date.booked[i].year << "]" << "\t" << "< " << *day_name << " > |" << endl;
    suitable_doctor[i].day_name = *day_name;
    cout << "         ------------------------------------------------------------\n";
    Show_Available_Time(i, suitable_doctor, day_name, index, j, 0, suitable_date);
}
bool Search_For_Doctors(int i, doc suitable_doctor[], string* day_name, int day, int month, int year, int hour, int min)
{
    bool found = false;
    // *day_name = calender_date(day, month);
    // int index = 0;
    int j = dayy(*day_name) - 1;
    if (suitable_doctor[i].Work_Date[j].day == *day_name)
    {
        for (int k = 0; k < suitable_doctor[i].Appointments.NUM_OF_APPOINTMENTS_BOOKED; k++)
        {
            if (suitable_doctor[i].Appointments.booked[k].day == day &&
                suitable_doctor[i].Appointments.booked[k].month == month &&
                suitable_doctor[i].Appointments.booked[k].year == year)
            {
                for (int l = 0; l < suitable_doctor[i].Work_Date[j].num_sessions; l++)
                {

                    if (hour > -1 && min > -1 && suitable_doctor[i].Work_Date[j].All_Sessions[l].B_hour == hour &&
                        suitable_doctor[i].Work_Date[j].All_Sessions[l].B_min == min)
                    {
                        if (suitable_doctor[i].Work_Date[j].All_Sessions[l].booked) return false;
                        else return true;
                    }
                    else if (suitable_doctor[i].Work_Date[j].All_Sessions[l].B_hour == suitable_doctor[i].Appointments.booked[k].hour &&
                        suitable_doctor[i].Work_Date[j].All_Sessions[l].B_min == suitable_doctor[i].Appointments.booked[k].min)
                    {
                        suitable_doctor[i].Work_Date[j].All_Sessions[l].booked = 1;
                        break;
                    }

                }
            }

        }
        for (int l = 0; l < suitable_doctor[i].Work_Date[j].num_sessions; l++)
        {
            if (today(suitable_doctor, day, month, year, i, j, l)) {
                suitable_doctor[i].Work_Date[j].All_Sessions[l].booked = 1;
                // continue;
            }
        }
        for (int l = 0; l < suitable_doctor[i].Work_Date[j].num_sessions; l++)
        {
            if (!suitable_doctor[i].Work_Date[j].All_Sessions[l].booked && !suitable_doctor[i].Work_Date[j].All_Sessions[l].breaks)
            {
                found = true;
                break;
            }
        }
    }
    return found;
}
void Show_Available_Time(int i, doc suitable_doctor[], string* day_name, int* index, int num_of_iterations, bool edit, appointment suitable_date, int num_doctor)
{
    int j = (dayy(*day_name) - 1);
    *index = 0;
    if (suitable_doctor[i].Work_Date[dayy(*day_name) - 1].day == *day_name)
    {
        for (int k = 0; k < suitable_doctor[i].Work_Date[j].num_sessions; k++)
        {
            if (suitable_doctor[i].Work_Date[j].All_Sessions[k].booked == 0 &&
                suitable_doctor[i].Work_Date[j].All_Sessions[k].breaks == 0)
            {
                if (edit)
                {
                    if (suitable_date.booked[i].hour == suitable_doctor[i].Work_Date[j].All_Sessions[k].B_hour &&
                        suitable_date.booked[i].min == suitable_doctor[i].Work_Date[j].All_Sessions[k].B_min) continue;
                }
                suitable_doctor[i].Work_Date[j].All_Sessions[k].number = ++ * index;
                cout << "         ---------------\n";
                cout << "         |  " << suitable_doctor[i].Work_Date[j].All_Sessions[k].number << ". ";
                cout << setw(2) << setfill(' ') << suitable_doctor[i].Work_Date[j].All_Sessions[k].B_hour << ":";
                cout << setw(2) << setfill(' ') << suitable_doctor[i].Work_Date[j].All_Sessions[k].B_min << "    |\n";
                if (*index == num_of_iterations) break;
            }
        }
    }

    cout << "         ---------------\n";
}
void Search_Doc_For_Day(int i, doc suitable_doctor[], string* day_name, int& w__day, appointment& suitable_date, int hour, int min)
{

    while (!Search_For_Doctors(i, suitable_doctor, day_name, suitable_date.booked[i].day, suitable_date.booked[i].month, suitable_date.booked[i].year, hour, min))//, num_doctor, doc_num, suitable_date))
    {
        cout << "tooooooooooooooooooooooooooooooooooooooooot\n";//test
        *day_name = days[w__day % 7];
        calender_date(day_name, suitable_date.booked[i].day, suitable_date.booked[i].month, suitable_date.booked[i].year, w__day);
    }

}
void Save_Session_Details(int i, doc suitable_doctor[], int* NUMBER, appointment& suitable_date, string* day_name)
{
    int j = (dayy(*day_name) - 1);

    for (int k = 0; k < suitable_doctor[i].Work_Date[j].num_sessions; k++)
    {
        if (suitable_doctor[i].Work_Date[j].All_Sessions[k].number == *NUMBER)
        {
            suitable_date.booked[i].hour = suitable_doctor[i].Work_Date[j].All_Sessions[k].B_hour;
            suitable_date.booked[i].min = suitable_doctor[i].Work_Date[j].All_Sessions[k].B_min;
            suitable_date.booked[i].duration = suitable_doctor[i].Work_Date[j].duration;
            suitable_date.booked[i].doc_speciality = suitable_doctor[i].specialty;
            break;
        }
    }
}
void booking_confirmation_AndSave(int i, doc suitable_doctor[], doc doctor[], appointment& suitable_date, pat patient[], int current_patient, int last_doc_array)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //save data for patient
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].doctor_name = suitable_doctor[i].first_name;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].doc_username = suitable_doctor[i].user_name;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0] = suitable_date.booked[i];
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].patient_name
        = patient[current_patient].first_name;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].patient_user_name
        = patient[current_patient].username;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].patient_age
        = patient[current_patient].age;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].booked = 1;
    patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].day_name
        = calender_date(patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].day,
            patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].month,
            patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].year);


    //save data for doctor

    for (int j = 0; j < last_doc_array; j++)
    {
        if (doctor[j].user_name == suitable_doctor[i].user_name)
        {
            doctor[j].count_of_rates = suitable_doctor[i].count_of_rates;
            doctor[j].avg_rates = suitable_doctor[i].avg_rates;
            doctor[j].rate[current_patient] = suitable_doctor[i].rate[current_patient];
            cout << "kkkkkkkkkk      " << doctor[j].count_of_rates << doctor[j].avg_rates << doctor[j].rate[current_patient] << endl;
            doctor[j].Appointments.booked[doctor[j].Appointments.NUM_OF_APPOINTMENTS_BOOKED] =
                patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0];
            doctor[j].Appointments.NUM_OF_APPOINTMENTS_BOOKED++;
            break;
        }
    }


    SetConsoleTextAttribute(h, 6);
    cout << "   << Appointment has been booked successfully! >>\n";
    SetConsoleTextAttribute(h, 8);
    cout << "  __________________________________________________\t\n\n";
    cout << "  >> Now you have an appointment with Dr / "
        << patient[current_patient]
        .appointments[patient[current_patient].num_of_appointments_booked]
        .doctor_name
        << "\n     on < " << patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].day_name
        << " >  [ " << patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].day << " / "
        << patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].month << " ] "
        << " at " << right << setw(2) << setfill('0') <<
        patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].hour
        << " : " << setw(2) << setfill('0') << patient[current_patient].appointments[patient[current_patient].num_of_appointments_booked].booked[0].min
        << " O'clock\n";
    cout << "  __________________________________________________\t\n\n";
    SetConsoleTextAttribute(h, 7);
    patient[current_patient].num_of_appointments_booked++;
}
bool book_an_appointment(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array, bool search_doc_by_name)
{
    appointment suitable_date = SUITALE_DATE;
    appointment Suitable_Date = {};
    int* doc_num = new int(*DOC_NUM);
    int month_value[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    time_t t = time(0);
    tm* tmp = localtime(&t);
    int* index = new int(0);
    int* NUMBER = new int(0);
    bool* found = new bool(0);
    int Case = 0;
    string* day_name = new string;
    string a = "\0";
    int* num_doctor = new int(0), way_number;
    bool search_for_another_time = true;
    int  w__day = tmp->tm_wday + 2, i = 0;
    if (!search_doc_by_name) Suitable_Doctors_by_speciality(doc_num, last_doc_array, suitable_doctor, doctor);
    cout << "  Do you want to search for a certain time ? ( y / n )\n  ";
    if (confirm())
    {
        system("CLS");
        if (search_doc_by_name)
        {
            profile(suitable_doctor, 0);
        }
        cout << "  Choose a suitable way for you..\n\n";
        cout << "  1. The date.\n\n";
        cout << "  2. The day.\n\n";
        way_number = input(1, 2);
        do {
            Case = 0;
            if (way_number == 1)
            {
                input_date(Suitable_Date, day_name);
            }
            else
            {
                *day_name = day_Display();
                if (!Suitable_Doctors_by_day_name(doc_num, suitable_doctor, day_name)) return false;
            }
            for (int i = 0; i < *doc_num; i++)
            {
                suitable_date.booked[i].day = Suitable_Date.booked[0].day;
                suitable_date.booked[i].month = Suitable_Date.booked[0].month;
                suitable_date.booked[i].year = Suitable_Date.booked[0].year;
                choose_by_certain_time(i, *doc_num, suitable_date, suitable_doctor, way_number, search_for_another_time, day_name, index);
            }
            if (search_for_another_time)
            {
                cout << "  [ " << suitable_date.booked[0].day << " / " << suitable_date.booked[0].month << " / " << suitable_date.booked[0].year << " ]  is busy\n\n";
                cout << "  1.Enter another date\n  2. Homepage\n";
                Case = input(1, 2);
                if (Case == 2) return false;
            }
        } while (Case);
    }
    else
    {
        if (!search_doc_by_name)
        {
            system("CLS");
            for (int i = 0; i < *doc_num; i++)
            {
                suitable_date.booked[i].day = tmp->tm_mday;
                suitable_date.booked[i].month = tmp->tm_mon + 1;
                suitable_date.booked[i].year = tmp->tm_year + 1900;
                w__day = tmp->tm_wday + 2;
                *day_name = days[w__day - 1];
                view_suitable_doctor(i, suitable_doctor, day_name, index, w__day, suitable_date, 1);
            }
        }
        else // search_doc_by_name, i =0; so --> suitable_doctor.booked[i] --> suitable_doctor.booked[0]
        {
            bool k;
            suitable_date.booked[i].day = tmp->tm_mday;
            suitable_date.booked[i].month = tmp->tm_mon + 1;
            suitable_date.booked[i].year = tmp->tm_year + 1900;
            *day_name = days[w__day - 1];
            do {
                if (!(suitable_doctor[i].Work_Date[dayy(*day_name) - 1].day == *day_name)) {
                    *day_name = days[w__day % 7];//w__day bta3 el yom el 2bloo //sunday -> w__day = 2... so monday -> days[2] ->days[w__day ] 
                    calender_date(day_name, suitable_date.booked[i].day, suitable_date.booked[i].month, suitable_date.booked[i].year, w__day);
                    // w__day++;
                }
            } while (!(suitable_doctor[i].Work_Date[(dayy(*day_name) - 1)].day == *day_name));
            suitable_doctor[i].day_name = *day_name;
        }
    }
    if (!search_doc_by_name)
    {
        cout << "\n  Enter the number of doctor you want : ";
        i = input(1, *doc_num);
    }
    for (int S_doctor_index = 0; S_doctor_index < *doc_num; S_doctor_index++)
    {
        if (suitable_doctor[S_doctor_index].number == i)
        {
            i = S_doctor_index;
            break;
        }
    }
    //cout << " Day_name " << suitable_doctor[i].day_name << endl;
    *day_name = suitable_doctor[i].day_name;

    if (suitable_doctor[i].Work_Date[(dayy(*day_name) - 1)].day == *day_name)
    {
        while (search_doc_by_name)
        {
            system("CLS");
            profile(suitable_doctor, i);
            *index = 0;
            Search_Doc_For_Day(i, suitable_doctor, day_name, w__day, suitable_date);
            cout << "       ________________________________________________________\n\n";
            cout << "              [ " << suitable_date.booked[i].day << " / " << suitable_date.booked[i].month << " / "
                << suitable_date.booked[i].year << "]" << "\t" << "< " << *day_name << " >" << endl;
            cout << "       ________________________________________________________\n\n";
            Show_Available_Time(i, suitable_doctor, day_name, index, suitable_doctor[i].Work_Date[(dayy(*day_name) - 1)].num_sessions, 0,
                suitable_date, 0);
            cout << "  1. This available date is suitable\n";
            cout << "  2. Search for the next available date\n";
            cout << "  3. Homepage\n";
            Case = input(1, 3);
            if (Case == 1) break;
            else if (Case == 3) return false;
            *day_name = days[w__day % 7];
            calender_date(day_name, suitable_date.booked[i].day, suitable_date.booked[i].month, suitable_date.booked[i].year, w__day);
            // w__day++;
        }
        if (!search_doc_by_name)
        {
            cout << "\n  All available times for the doctor: \n";
            cout << "  ---------------------------------\n";
            Show_Available_Time(i, suitable_doctor, day_name, index, suitable_doctor[i].Work_Date[(dayy(*day_name) - 1)].num_sessions, 0,
                suitable_date, 0);
            cout << "  ---------------------------------\n\n";
        }
        cout << "  Enter the number of time you want : ";
        *NUMBER = input(1, *index);
        cout << "  Do you want to confirm ? ( y / n )\n  ";

        if (confirm())
        {
            Save_Session_Details(i, suitable_doctor, NUMBER, suitable_date, day_name);
            rating(suitable_doctor, i, current_patient, last_doc_array);
            booking_confirmation_AndSave(i, suitable_doctor, doctor, suitable_date, patient, current_patient, last_doc_array);

        }
        return true;
    }

}
int dayy(string day)
{
    for (int i = 0; i < 7; i++)
    {
        if (days[i] == day) return i + 1;
    }
}
void reference_time(int year2, int day1, int& day2)
{
    const int year1 = 2021; // el reference beta3y
    day2 = (year2 - year1) + ((year2 - year1) / 4);
    day2 %= 7;
    day2 = (day1 - day2);
    if (day2 <= 0) day2 += 7;
}
void leap_year(int YEAR)
{
    if ((YEAR % 4 == 0) && (YEAR % 100 != 0) || (YEAR % 400 == 0)) month_value[1] = 29;
    else month_value[1] = 28; // Leap Year
}

void calender_date(string* day_name, int& DAY, int& MONTH, int& YEAR, int& w__day)
{
    int w_day;
    leap_year(YEAR);
    w_day = dayy(*day_name);

    if (w_day >= (w__day))
        DAY += (w_day - (w__day));
    else
        DAY += (7 - (w__day)) + w_day;
    if (DAY > month_value[MONTH - 1])
    {
        DAY %= month_value[MONTH - 1];
        MONTH = (MONTH)+1;
        if (MONTH > 12)
        {
            YEAR++;
            MONTH %= 12;
        }
    }
    w__day = w_day;
}
string calender_date(int day, int month, int year)
{
    int Days = 0;
    int md = 0;
    const int mon = 1;
    const int w__day = 1;
    // reference time  //Saturday --> w_day = 1 , tmp->tm_mon = 1 
    reference_time(year, 2, md);
    if (month == mon && day < md && year > 2021)   return days[7 - (md - day)];

    leap_year(year);
    if (month == mon)
        Days = (day - md); //3dd el ayam from el localtime to day el ana 3yzah
    else
    {
        Days += (month_value[mon - 1] - md);
        for (int i = mon; i < month - 1; i++)//4-> da index 4ahr 5amsa and so on
        {
            Days += month_value[i];
        }
        Days += day; //3dd el ayam from el localtime to day el ana 3yzah
    }
    Days += (w__day)-1; //bazod tarteb el week el sa7 l2'no by3taber el localtime hwa bedayet el 2sbo3....(-1) 34an 3ayza index el yom m4 el w_day
    Days %= 7;
    return days[Days];
}

string day_Display()
{
    int w__day = tmp->tm_wday;
    cout << "  Choose from these days :\n";
    cout << "  -------------------------\n";
    for (int i = 0; i < 7; ++i)
    {
        cout << "  " << i + 1 << ". " << days[i] << "\n\n";
    }
    cout << "\n  ";
    return  days[input(1, 7) - 1];
}

// day_name -> suitable_date[].booked[]
//suitable_date -> by reference
void edit_appointment(int* DOC_NUM, appointment& SUITALE_DATE, pat patient[], doc suitable_doctor[], doc doctor[], int current_patient, int last_doc_array)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    booking doctor_deletion;
    bool found = false;
    int* d = new int;
    int* m = new int;
    int* y = new int;
    bool not__exist = true;
    bool exist = false;
    int num_doctor = 1;
    bool GoBack = false;
    int num, o;
    string* day_name = new string;
    int* index = new int(1);
    string message;
    cout << "  Enter the number of appointment to modify it : ";
    num = input(1, patient[current_patient].num_of_appointments_booked);
    Suitable_Doctors_by_speciality(DOC_NUM, last_doc_array, suitable_doctor, doctor, patient[current_patient].appointments[num - 1].booked[0].doc_speciality);
    ///
    SUITALE_DATE.doc_username = patient[patient->ID].appointments[num - 1].doc_username;
    *day_name = patient[patient->ID].appointments[num - 1].booked[0].day_name;
    int w__day = dayy(*day_name);
    int day_num = dayy(*day_name);
    do {
        system("CLS");
        cout << endl << endl;
        SetConsoleTextAttribute(h, 8);
        cout << "\n\   You will choose number from the table below: \n";
        SetConsoleTextAttribute(h, 7);
        cout << "  _________________________________________________________________________________\n\n";
        cout << "     |    [2] Day / Date        |  [3] Time  | [1] Doctor's info [name - username] \n";
        cout << "  ---------------------------------------------------------------------------------\n";
        cout << "     | ";


        cout << left << setw(9) << patient[current_patient].appointments[num - 1].booked[0].day_name << " " << setw(2) << setfill(' ') << patient[current_patient].appointments[num - 1].booked[0].day << " / "
            << setw(2) << setfill(' ') << patient[patient->ID].appointments[num - 1].booked[0].month << " / "
            << patient[patient->ID].appointments[num - 1].booked[0].year << " |    "
            << setw(2) << setfill(' ') << patient[patient->ID].appointments[num - 1].booked[0].hour << ":"
            << setw(2) << setfill('0') << patient[patient->ID].appointments[num - 1].booked[0].min
            << "   | Dr. " << patient[current_patient].appointments[num - 1].doctor_name << " - "
            << patient[current_patient].appointments[num - 1].doc_username << endl;


        cout << "  _________________________________________________________________________________\n\n";
        cout << "     | [4] > Choose a new appointment instead\n";
        cout << "     | [5] > Delete appointment \n";
        cout << "     | [6] > Back \n";
        cout << "  _________________________________________________________________________________\n\n";
        cout << "   your choice: ";

        //34an lazem el parameter ykon pointer or nkhle2h variable 3ady me4 pointer
        int Case = 0;
        Case = input(1, 6);
        do {

            switch (Case)
            {
            case 1: //change doctor but same time    done
                Case = 0;
                found = false;
                *index = 1;
                for (int i = 0; i < *DOC_NUM; i++)
                {
                    suitable_doctor[i].number = 0;
                    if (patient[patient->ID].appointments[num - 1].doc_username == suitable_doctor[i].user_name) continue;
                    if (Search_For_Doctors(i, suitable_doctor, day_name,
                        patient[patient->ID].appointments[num - 1].booked[0].day,
                        patient[patient->ID].appointments[num - 1].booked[0].month,
                        patient[patient->ID].appointments[num - 1].booked[0].year,
                        patient[patient->ID].appointments[num - 1].booked[0].hour,
                        patient[patient->ID].appointments[num - 1].booked[0].min)) //hour& min
                    {
                        cout << "  " << *index << ". ";
                        suitable_doctor[i].number = *index;
                        View_Doctor_info(suitable_doctor, i);
                        cout << "\n\n";
                        ++* index;
                        SUITALE_DATE.booked[i] = patient[patient->ID].appointments[num - 1].booked[0];
                        found = true;
                    }
                }
                if (found)
                {
                    cout << "  Enter the number of doctor you want : ";
                    int* NUMBER = new int(input(1, *index - 1)); //number of appointment
                    for (int S_doctor_index = 0; S_doctor_index < *DOC_NUM; S_doctor_index++)
                    {
                        if (suitable_doctor[S_doctor_index].number == *NUMBER)
                        {
                            *NUMBER = S_doctor_index;
                            break;
                        }
                    }
                    //Save_Session_Details(i, suitable_doctor, NUMBER, SUITALE_DATE);
                    cout << "  Do you want to confirm ? ( y / n )\n  ";
                    if (confirm())
                    {
                        //save
                        for (int i = 0; i < last_doc_array; i++)
                        {
                            if (patient[patient->ID].appointments[num - 1].doc_username == doctor[i].user_name)
                            {
                                remove_7ogozat(patient, doctor, i, patient->ID, num - 1);
                                break;
                            }
                        }
                        int num_of_appointments_booked = patient[current_patient].num_of_appointments_booked;
                        patient[current_patient].num_of_appointments_booked = num - 1;
                        booking_confirmation_AndSave(*NUMBER, suitable_doctor, doctor, SUITALE_DATE, patient, current_patient, last_doc_array);
                        patient[current_patient].num_of_appointments_booked = num_of_appointments_booked;
                    }
                    else  cout << "  well :)\tI don't know what to say to you, anyway we hope you exit the program :)\n  ";
                }
                else cout << "  Sorry, There isn't any doctor available on your suitable date.\n";
                Sleep(1500);
                GoBack = true;
                break;
            case 2:// same hour& doctor   done except for else (!Search_For_Doctors)
                // start displaying appointments for this doctor from : (but same hour)
                // Next date from this date that you wanna change (i think true :)
                Case = 0;
                SUITALE_DATE.booked[0] = patient[patient->ID].appointments[num - 1].booked[0];

                input_date(SUITALE_DATE, day_name);
                w__day = dayy(*day_name);

                for (int i = 0; i < *DOC_NUM; i++)
                {
                    if (patient[patient->ID].appointments[num - 1].doc_username == suitable_doctor[i].user_name)
                    {
                        if (Search_For_Doctors(i, suitable_doctor, day_name,
                            SUITALE_DATE.booked[0].day, SUITALE_DATE.booked[0].month, SUITALE_DATE.booked[0].year,
                            patient[patient->ID].appointments[num - 1].booked[0].hour,
                            patient[patient->ID].appointments[num - 1].booked[0].min))
                        {
                            cout << "  Do you want to confirm ? ( y / n )\n  ";
                            if (confirm())
                            {
                                SUITALE_DATE.booked[i] = SUITALE_DATE.booked[0];
                                for (int j = 0; j < last_doc_array; j++)
                                {
                                    if (doctor[j].user_name == patient[current_patient].appointments[num - 1].doc_username)
                                    {
                                        remove_7ogozat(patient, doctor, j, patient->ID, num - 1);
                                        break;
                                    }
                                }
                                //motakarreen
                                int num_of_appointments_booked = patient[current_patient].num_of_appointments_booked;
                                patient[current_patient].num_of_appointments_booked = num - 1;
                                booking_confirmation_AndSave(i, suitable_doctor, doctor, SUITALE_DATE, patient, current_patient, last_doc_array);
                                patient[current_patient].num_of_appointments_booked = num_of_appointments_booked;
                            }
                            else
                            {
                                cout << "  well :)\tI don't know what to say to you, anyways we hope you exit the program :)\n  ";
                            }
                        }
                        else
                        {
                            cout << "  There is no available time on the date you want \n  The nearest available time for the date you want is on ";

                            do {
                                *day_name = days[(w__day % 7)];
                                SUITALE_DATE.booked[i] = SUITALE_DATE.booked[0];
                                calender_date(day_name, SUITALE_DATE.booked[i].day, SUITALE_DATE.booked[i].month, SUITALE_DATE.booked[i].year, w__day);
                                Search_Doc_For_Day(i, suitable_doctor, day_name, w__day, SUITALE_DATE,
                                    patient[patient->ID].appointments[num - 1].booked[0].hour,
                                    patient[patient->ID].appointments[num - 1].booked[0].min);
                                SUITALE_DATE.booked[i].day_name = *day_name;
                                //error, garbage
                                cout << "  \" " << *day_name << " \"\t\n"
                                    << "  ( " << SUITALE_DATE.booked[i].day << " / "
                                    << SUITALE_DATE.booked[i].month << " / "
                                    << SUITALE_DATE.booked[i].year << " )\n\n";
                                cout << "  -------------------------------------------------------------------\n\n";
                                int choice;
                                cout << "  1. This available date is suitable\n";
                                cout << "  2. Show another appointment\n";
                                cout << "  3. Back\n";
                                choice = input(1, 3);
                                if (choice == 1)
                                {
                                    // input(1, );
                                    cout << "  Do you want to confirm ? ( y / n ) ";
                                    if (confirm())
                                    {
                                        for (int j = 0; j < last_doc_array; j++)
                                        {
                                            if (doctor[j].user_name == patient[current_patient].appointments[num - 1].doc_username)
                                            {
                                                remove_7ogozat(patient, doctor, j, patient->ID, num - 1);
                                                break;
                                            }
                                        }
                                        //motakarer
                                        int x = patient[current_patient].num_of_appointments_booked;
                                        patient[current_patient].num_of_appointments_booked = num - 1;
                                        booking_confirmation_AndSave(i, suitable_doctor, doctor, SUITALE_DATE, patient, current_patient, last_doc_array);
                                        patient[current_patient].num_of_appointments_booked = x;
                                    }
                                    else  GoBack = true;
                                    break;
                                }
                                else if (choice == 3)
                                {
                                    GoBack = true;
                                    break;
                                }
                            } while (true);
                        }
                    }
                }
                break;
            case 3://same doctor & date -same day

                for (int i = 0; i < *DOC_NUM; i++)
                {
                    SUITALE_DATE.booked[i] = patient[patient->ID].appointments[num - 1].booked[0];
                    if (patient[patient->ID].appointments[num - 1].doc_username == suitable_doctor[i].user_name)
                    {
                        if (Search_For_Doctors(i, suitable_doctor, day_name,
                            patient[patient->ID].appointments[num - 1].booked[0].day,
                            patient[patient->ID].appointments[num - 1].booked[0].month,
                            patient[patient->ID].appointments[num - 1].booked[0].year))
                        {
                            Show_Available_Time(i, suitable_doctor, day_name, index, suitable_doctor[i].Work_Date[dayy(*day_name) - 1].num_sessions);

                            cout << "  Enter the number of time you want : ";
                            int* NUMBER = new int(input(1, *index)); //number of appointment
                            Save_Session_Details(i, suitable_doctor, NUMBER, SUITALE_DATE, day_name);

                            cout << "  Do you want to confirm ? ( y / n )\n  ";
                            if (confirm())
                            {
                                //save
                                for (int i = 0; i < last_doc_array; i++)
                                {
                                    if (doctor[i].user_name == patient[current_patient].appointments[num - 1].doc_username)
                                    {
                                        remove_7ogozat(patient, doctor, i, patient->ID, num - 1);
                                        break;
                                    }
                                }
                                int x = patient[current_patient].num_of_appointments_booked;
                                patient[current_patient].num_of_appointments_booked = num - 1;
                                booking_confirmation_AndSave(i, suitable_doctor, doctor, SUITALE_DATE, patient, current_patient, last_doc_array);
                                patient[current_patient].num_of_appointments_booked = x;
                            }
                        } //m
                        else
                        {
                            cout << " The doctor you want does not have another available time on "
                                << patient[patient->ID].appointments[num - 1].booked[0].day << " / "
                                << patient[patient->ID].appointments[num - 1].booked[0].month << " / "
                                << patient[patient->ID].appointments[num - 1].booked[0].year
                                << "\n  you can do the following:  \n  1. Choose another doctor\n  2. Choose another day with the same doctor\n 3. go back\n  choice: ";
                            Case = 0; return;
                            Case = input(1, 2);
                            //same date (another doctor)
                            switch (Case)
                            {
                            case 1:
                                for (int j = 0; j < last_doc_array; j++)
                                {
                                    if (patient[patient->ID].appointments[num - 1].doc_username ==
                                        suitable_doctor[j].user_name) continue;
                                    if (Search_For_Doctors(j, suitable_doctor, day_name,
                                        patient[patient->ID].appointments[num - 1].booked[0].day,
                                        patient[patient->ID].appointments[num - 1].booked[0].month,
                                        patient[patient->ID].appointments[num - 1].booked[0].year))
                                    {
                                        suitable_doctor[j].number = num_doctor++;
                                        cout << suitable_doctor[j].number << ". ";
                                        View_Doctor_info(suitable_doctor, j);
                                        Show_Available_Time(j, suitable_doctor, day_name, index, 0, 1, SUITALE_DATE);
                                        if (*index > 1)
                                        {
                                            exist = true;
                                        }
                                    }
                                }
                                if (exist)
                                {
                                    cout << "  Enter the number of doctor you want : ";
                                    num_doctor = input(1, num_doctor - 1);
                                    for (int i = 0; i < *DOC_NUM; i++)
                                    {
                                        if (suitable_doctor[i].number == num_doctor)
                                        {
                                            Show_Available_Time(i, suitable_doctor, day_name, index, suitable_doctor[i].Work_Date[dayy(*day_name) - 1].num_sessions);
                                            cout << "  Enter the number of time you want : ";
                                            *index = input(1, *index);
                                            cout << "  Do you want to confirm ? ( y / n ) \n  ";
                                            if (confirm())
                                            {
                                                Save_Session_Details(i, suitable_doctor, index, SUITALE_DATE, day_name);
                                                booking_confirmation_AndSave(i, suitable_doctor, doctor, SUITALE_DATE,
                                                    patient, current_patient, last_doc_array);
                                            }
                                            else
                                                cout << "  well :)\tI don't know what to say to you, anyway we hope you exit the program :)\n  ";
                                            break;
                                        }
                                    }

                                }
                                else
                                {
                                    cout << "  No available Doctor on the date you want";
                                    GoBack = true;
                                }
                                break;

                            case 2: GoBack = true;
                                break;
                            }
                        }
                    }

                }
                break;
            case 4:
                Case = 0;
                o = patient[current_patient].num_of_appointments_booked;
                book_an_appointment(DOC_NUM, SUITALE_DATE, patient, suitable_doctor, doctor,
                    current_patient, last_doc_array);
                if (o < patient[current_patient].num_of_appointments_booked) delete_appointment(patient, current_patient, doctor, last_doc_array, num), GoBack = false;
                else GoBack = true;
                break;
            case 5:
                Case = 0;
                delete_appointment(patient, current_patient, doctor, last_doc_array, num);
                break;
            case 6:
                GoBack = false;
                break;
            }
        } while (Case == 1);
    } while (GoBack);
}
float avg_rates(doc suitable_doctor[], int index_doctor, int current_patient, int last_patient_array)
{
    suitable_doctor[index_doctor].avg_rates *= last_patient_array - 1;
    suitable_doctor[index_doctor].avg_rates += suitable_doctor[index_doctor].rate[current_patient];
    suitable_doctor[index_doctor].count_of_rates++;
    return suitable_doctor[index_doctor].avg_rates /= last_patient_array;
}
void arrange(doc doctor[], int last_doc_array) // c= a+b ///a=c-a; b=c-a;
{
    for (int i = last_doc_array - 1; i >= 0; i--)
    {
        for (int j = last_doc_array - 1; j >= 0; j--)
            if (doctor[i].avg_rates > doctor[j].avg_rates)
            {
                doc a = doctor[i];
                doctor[i] = doctor[j];
                doctor[j] = a;
            }
    }
}
void rating(doc suitable_doctor[], int index_doctor, int current_patient, int last_doc_array)
{
    cout << "  Enter rate ";
    suitable_doctor[index_doctor].rate[current_patient] = input(0, 5);
    //cin.ignore(); //repeat rating
    cout << "       "; RATING(float(suitable_doctor[index_doctor].rate[current_patient]));
    suitable_doctor[index_doctor].avg_rates = avg_rates(suitable_doctor, index_doctor, current_patient);
    //arrange(suitable_doctor, last_doc_array); edit
}
void RATING(float rate)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 1; i <= int(rate); i++)
    {
        SetConsoleTextAttribute(h, 6);
        cout << "* ";
    }
    SetConsoleTextAttribute(h, 7);
    // cout << "\n";
}
void Rate()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int rate;
    cout << "  Enter the rate from 0 to 5 :  ";
    rate = input(0, 5);
    cout << "\n\t\t  Your Rate :    ";
    RATING(rate);
    SetConsoleTextAttribute(h, 7);
    cout << "\n\n";
    cout << "  Thank You for your rating!\n\n  We hope we meet your expectations!\n\n";
}
int cin_daynum(int& flag)
{
    if (flag == 1) return input(1, 29);
    else if (flag == 2) return input(1, 28);
    else if (flag == 3) return input(1, 30);
    else if (flag == 4) return input(1, 31);
}
int cin_day(int month, int year)
{
    int flag;
    if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))) flag = 1;
    else if ((month == 2) && (year != 2024 && year != 2028)) flag = 2;
    else if ((month == 4 || month == 6 || month == 9 || month == 11)) flag = 3;
    else flag = 4;
    return cin_daynum(flag);
}
void history_list_display(pat patient[], int current_patient)
{
    cout << "  ---------------------------------------------------------------------------------------------------------------------\n";
    cout << "  No.|    Day   |     Date      |    Time     | Duration |        Speciality        |  Doctor's name - username\n";
    cout << "  ---------------------------------------------------------------------------------------------------------------------\n\n";

    for (int A = 0; A < patient[current_patient].history_list_size; A++)
    {
        cout << "  " << setw(3) << setfill(' ') << A + 1 << "| ";
        cout << setw(9) << patient[current_patient].history[A].booked[0].day_name << "| "
            << setw(2) << setfill(' ') << patient[current_patient].history[A].booked[0].day << " / "
            << setw(2) << setfill(' ') << patient[current_patient].history[A].booked[0].month << "/ "
            << patient[current_patient].history[A].booked[0].year << " |    "
            << setw(2) << setfill(' ') << patient[current_patient].history[A].booked[0].hour << ":"
            << setw(2) << setfill(' ') << patient[current_patient].history[A].booked[0].min << "    |    "
            << patient[current_patient].history[A].booked[0].duration << "    | "
            << left << setw(25) << patient[current_patient].history[A].booked[0].doc_speciality << "| "
            << patient[current_patient].history[A].doctor_name << " - " << patient[current_patient].history[A].doc_username << "\n";
        cout << "  ---------------------------------------------------------------------------------------------------------------------\n";

    }
}
void History_list(pat patient[], int current_patient, doc doctor[], int last_doc_array) {
    time_t t = time(0);
    tm* tmp = localtime(&t);
    int day = tmp->tm_mday,
        month = (tmp->tm_mon + 1),
        year = 1900 + tmp->tm_year,
        hour = tmp->tm_hour,
        min = tmp->tm_min, End_time;

    //transfere from appointment to history array
    for (int i = 0; i < patient[current_patient].num_of_appointments_booked; i++)
    {   //will compare with minutes
        End_time = ((60 * patient[current_patient].appointments[i].booked[0].hour) + patient[current_patient].appointments[i].booked[0].min + patient[current_patient].appointments[i].booked[0].duration);
        //history year = year , month = month , day< day || year = year , month< month || year< year
        if ((patient[current_patient].appointments[i].booked[0].year < year) ||
            (patient[current_patient].appointments[i].booked[0].year == year && patient[current_patient].appointments[i].booked[0].month < month) ||
            (patient[current_patient].appointments[i].booked[0].year == year && patient[current_patient].appointments[i].booked[0].month == month &&
                patient[current_patient].appointments[i].booked[0].day < day) || (patient[current_patient].appointments[i].booked[0].year == year &&
                    patient[current_patient].appointments[i].booked[0].month == month && patient[current_patient].appointments[i].booked[0].day == day && End_time < (60 * hour + min)))
        {
            patient[current_patient].history[patient[current_patient].history_list_size] = patient[current_patient].appointments[i];
            delete_appointment(patient, current_patient, doctor, last_doc_array, (i + 1), 1);
            i--;
            patient[current_patient].history_list_size++;
        }
    }
}
void cin_position(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);

}
void View_Doctor_info(doc suitable_doctor[], int i)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


    cout << "  |";
    if (suitable_doctor[i].gender == 'm')SetConsoleTextAttribute(h, 9);
    else SetConsoleTextAttribute(h, 13);
    cout << "  Dr. ";
    cout << suitable_doctor[i].first_name << " "
        << suitable_doctor[i].last_name;
    SetConsoleTextAttribute(h, 7);
    cout << "  (" << suitable_doctor[i].years_of_experience << " years of experience)\n";
    cout << "  ___________________________________________________________________\n\n";
    cout << "         |  "; RATING(suitable_doctor[i].avg_rates);
    cout << "\t Overall Rating from " << suitable_doctor[i].count_of_rates << " visitors \n";

    cout << "         |  Fees: " << suitable_doctor[i].Fees << " EGP\n";
    cout << "         ------------------------------------------------------------\n";

}

void clear_history(pat patient[], int current_patient) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < patient[current_patient].history_list_size; i++)
    {
        patient[current_patient].history[i] = {};
    }
    patient[current_patient].history_list_size = 0;
    ;
    SetConsoleTextAttribute(h, 11);
    cout << "\n  << your History is cleared successfully! >>\n\n";
    SetConsoleTextAttribute(h, 7);
}
void font_and_color(int font_size_x, int font_size_y, int color, int bold)
{
    // system("CLS");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    static CONSOLE_FONT_INFOEX  fontex, acrobat;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = bold; //bold
    fontex.dwFontSize.X = font_size_x;
    fontex.dwFontSize.Y = font_size_y;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    // after function call, color back to 7
    // SetConsoleTextAttribute(h, 7); 
    // system("CLS");  , Sleep(m_sec);
}
void text_edit(string Text, int font_size_x, int font_size_y, int color, int bold, int m_sec)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    font_and_color(font_size_x, font_size_y, color, bold);
    cout << Text;
    Sleep(m_sec);
    SetConsoleTextAttribute(h, 7);
}
bool today(doc suitable_doctor[], int day, int month, int year, int i, int j, int k) {

    time_t t = time(0);
    tm* tmp = localtime(&t);
    int session_start, current_time, hour, min;
    //convert start time to minutes

    hour = suitable_doctor[i].Work_Date[j].All_Sessions[k].B_hour;
    min = suitable_doctor[i].Work_Date[j].All_Sessions[k].B_min;
    current_time = (60 * (tmp->tm_hour)) + (tmp->tm_min);

    if ((day == tmp->tm_mday) && (month == tmp->tm_mon + 1) && (year == 1900 + tmp->tm_year))
    {
        session_start = (60 * hour) + min;

        if (session_start < current_time)
            return true;

    }

    return false;
}
void welcome()
{
    //string n, s = "Welcome to VEZEETA";
    //for (int i = 0; i < s.size(); i++)
    //{
    //    n = "m\b";
    //    cin_position(46 + i, 8);
    //    n += s[i];
    //    if (i % 2 == 0) text_edit(n, 40, 40, 6, 400, 200);
    //    else if (i % 2 == 1) text_edit(n, 40, 40, 6, 400, 250);


    //}
    //text_edit("__________________________", 40, 40, 8, 400, 300);
    //cin_position(45, 10);
    //text_edit("______________________", 40, 40, 8, 400, 0);
    //Sleep(3000);
    //cin_position(46, 8);
    //cout << "                  ";
    //Sleep(250);
    //cout << "Welcome to VEZEETA";
    //cout << "                  ";
    //Sleep(250);
    //cout << "Welcome to VEZEETA";
    //system("CLS");
    //font_and_color(30, 30, 8, 100);
    //system("CLS");
    cin_position(46, 8);
    text_edit("W", 60, 60, 6, 400, 400);
    cin_position(47, 8);
    text_edit("e", 60, 60, 6, 400, 400);
    cin_position(48, 8);
    text_edit("l", 60, 60, 6, 400, 200);
    cin_position(49, 8);
    text_edit("co", 60, 60, 6, 400, 200);
    cin_position(51, 8);
    text_edit("me", 60, 60, 6, 400, 400);
    cin_position(54, 8);
    text_edit("t", 60, 60, 6, 400, 400);
    cin_position(55, 8);
    text_edit("o", 60, 60, 6, 400, 400);
    cin_position(57, 8);
    text_edit("v", 60, 60, 6, 400, 400);
    cin_position(58, 8);
    text_edit("e", 60, 60, 6, 400, 400);
    cin_position(59, 8);
    text_edit("zee", 60, 60, 6, 400, 400);
    cin_position(62, 8);
    text_edit("t", 60, 60, 6, 400, 400);
    cin_position(63, 8);
    text_edit("a", 60, 60, 6, 400, 400);
    cin_position(43, 9);
    text_edit("__________________________", 40, 40, 8, 400, 400);
    cin_position(45, 10);
    text_edit("______________________", 40, 40, 8, 400, 0);
    Sleep(3000);
    system("CLS");
    font_and_color(30, 30, 8, 100);
    system("CLS");
}
