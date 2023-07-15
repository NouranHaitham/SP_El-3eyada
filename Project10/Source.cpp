#include"struct.h"
#include"doctor.h"
#include"patient.h"

bool Exit = 0;
bool nn = 1;
int main()
{
	//if (Exit) return 0;
	//doc doctor[size_of_arrs] = {};
	//pat patient[size_of_arrs] = {};
	doc doctor[size_of_arrs] = {
		  {0,'f',"nouran", "reda", "Anesthesiology",10,1, {{"Saturday", 2,0,6,0,30,6,{{2,0,2,30,0,0,0},{2,30,3,0,0,0,0},{3,0,3,30,0,0,0},
			{3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,0,0,0},{5,0,5,30,0,0,0},{5,30,6,0,0,0,0}}},{},{},{},{},{},{}},
		  {2,
		  {{ "Saturday" , 20 , 5 , 2023 ,2,0 , 30 , "Anesthesiology" , "Mona" ,
		  "Mona" , 25 , 1 , 0 },{ "Saturday" , 27, 5 , 2023 ,3,0 , 30 , "Anesthesiology" , "mariam" ,
		  "mariamm" , 30 , 1 , 0 } } , "nouran" , "nour"}
		  ,35,0,"nour",
		  "1234","email1@example.com","01234567891",0,{},5,0,250},


		  {0,'f',"Hagar", "Attya",
		   "Anesthesiology",10,2, { {},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,0,0,0},
							   {5,0,5,30,0,0,0},{5,30,6,0,1,0,0},{6,0,6,30,0,0,0},{6,30,7,0,0,0,0}}},{},{"Thursday", 0,0,2,0,15 ,8,{{0,0,0,15,0,0,0},{0,15,0,30,1,0,0},{0,30,0,45,0,0,0},
		  {0,45,1,0,0,0,0},{1,0,1,15,0,0,0},{1,15,1,30,1,0,0},{1,30,1,45,1,0,0},{1,45,2,0,0,0,0}}},{}
		  },{},35,3,"hagar","1234","email1@example.com","01234567891",0,{},4,0,50},



		   {0,'f',"mariam", "ahmed",
		   "Cardiology",20,2,
		  {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
		   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{},
		   {"Wednesday", 1,0,7,0,45,8,{{1,0,1,45,0,0,0},{1,45,2,30,0,0,0},{2,30,3,15,0,0,0},
		   {3,15,4,0,1,0,0},{4,0,4,45,1,0,0},{4,45,5,30,0,0,0},{5,30,6,15,0,0,0},{6,15,7,0,0,0,0}}},{},{}},{2,
		  {{ "Saturday" , 27 , 5 , 2023 ,4,0 , 30 , "Cardiology" , "Mona" ,
		  "Mona" , 25 , 1 , 0 },{ "Wednesday" , 24, 5 , 2023 ,2,30 , 25 , "Cardiology" , "nehal" ,
		  "nehal12" , 32 , 1 , 0 } } , "mariam" , "mariam"},40,1,"mariam",
		   "1234","email1@example.com","01234567891",0,{},2.5,0,300},



		  {0,'m',"Hassan", "Ahmed",
		   "Cardiology",10,2, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
		  {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}} ,{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
							   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}  },
		  {3,
		  {{ "Tuesday" , 1 , 6 , 2023 ,6,0 , 30 , "Cardiology" , "ramdan" ,
		  "ramadan_123" , 25 , 1 , 0 },{ "Tuesday" , 27, 8 , 2023 ,5,0 , 30 , "Cardiology" , "nehal" ,
		  "nehal12" , 32 , 1 , 0 } ,{ "Saturday" , 27 , 5 , 2023 ,4,0 , 30 , "Cardiology" , "Mona" ,
		  "Mona" , 25 , 1 , 0 } } , "Hassan" ,"hassan12"}
			  ,35,2,"hassan12",
		  "1234","email1@example.com","01234567891",0,{},1.2,0,100},


		  {0,'m',"Wagdy","mohamed","Hematology",10,1,{ {},{},{"Monday", 3, 0,6, 0, 30, 6,{{3,0,3,30,0,0,0},
		  {3,30,4,0,0,0,0},{4,0,4,30,1,0,0},{4,30,5,0,0,0,0},{5,0,5,30,0,0,0},{5,30,6,0,1,0,0}}},{},{},{},{}},{}, 42,
		  5,"wagdy123", "1234", "email1@example.com", "1234567891",{ } ,3.5, 0, 250 },


		  {0,'f',"hoda", "Ahmed",
		   "Cardiology",10,2, { {},{},{"Monday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
		   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0},{5,0,5,30,1,0,0}}},{},{},{"Thursday", 2,0,6,0,30,6,{{2,0,2,30,0,0,0},{2,30,3,0,0,0,0},{3,0,3,30,0,0,0},
		  {3,30,4,0,0,0,0},{4,0,4,30,1,0,0},{4,30,5,0,0,0,0},{5,0,5,30,0,0,0},{5,30,6,0,1,0,0}}},{}},{2,
		  {{ "Monday" , 19 , 6 , 2023 ,3,30 , 30 , "Cardiology" , "ramadan" ,
		  "ramadan_123" , 25 , 1 , 0 }, {"Thursday" , 6, 7 , 2023 ,3,30 , 30 , "Cardiology" , "chloe" ,
		  "chloe_123" , 30 , 1 , 0 } } , "hoda" ,"hoda123"} ,55,6,"hoda123",
		  "1234","email1@example.com","01234567891",0,{},1,0,180} ,



		  {0,'m',"Mohsen", "othman",
			   "Dermatology",10,3, { {"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{"Monday", 4,0,7,0,30,6,{{4,0,4,30,0,0,0},{4,30,5,0,0,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,0,0,0},{4,30,5,0,0,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},25,7,"mohsen12",
			   "1234","email1@example.com","01234577891",0,{},0,0,125},


		  {0,'m',"Aoad", "othman",
			   "Hematology",10,3, { {"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{}, {"Monday", 4,0,7,0,30,6,{{4,0,4,30,0,0,0},{4,30,5,0,0,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,0,0,0},{4,30,5,0,0,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{2,
			   {{ "Monday" , 31 , 7 , 2023 ,5,0 , 30 , "Hematology" , "chloe" ,
			   "chloe_123" , 30 , 1 , 0 }, {"Tuesday" ,22, 8 , 2023 ,4,30 , 30 , "Hematology" , "karen" ,
			   "karen_123" , 30 , 1 , 0 } } , "Aoad" ,"Aoda_12"}
			   ,25,7,"Aoda_12",
			   "1234","email1@example.com","01235567891",0,{},0,0,150},



		  { 0,'f',"amany", "ramzy",
			  "Hematology",10,2, {{},{},{"Monday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			  {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0},{5,0,5,30,1,0,0}}},{},{},
			  {"Thursday", 2,0,6,0,30,6,{{2,0,2,30,0,0,0},{2,30,3,0,0,0,0},{3,0,3,30,0,0,0},
			  {3,30,4,0,0,0,0},{4,0,4,30,1,0,0},{4,30,5,0,0,0,0},{5,0,5,30,0,0,0},{5,30,6,0,1,0,0}}},{}},{2,
			  {{ "Monday" , 4 , 9 , 2023 ,4,0 , 30 , "Hematology" , "Mona" ,
			  "Mona" , 25 , 1 , 0 },{"Thursday" , 7, 9 , 2023 ,3,0 , 30 ,"Hematology" , "mariam" ,
			  "mariamm" , 30 , 1 , 0 } } , "amany" , "amany_12"} ,55,6,"amany_12",
			  "1234","email1@example.com","01234567891",0,{},1,0,300 },


		  {0,'m', "mohannad", "metwally",
			  "immunology", 10, 2, { {"Saturday", 2,0,6,0,30,6,{{2,0,2,30,0,0,0},{2,30,3,0,0,0,0},{3,0,3,30,0,0,0},
			  {3,30,4,0,0,0,0},{4,0,4,30,1,0,0},{4,30,5,0,0,0,0},{5,0,5,30,0,0,0},{5,30,6,0,1,0,0}}},{},{},{},{"Wednesday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			  {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0},{5,0,5,30,1,0,0}}},{},{} },{2,
			  {{ "Saturday" , 20 , 8 , 2023 ,2,0 , 30 , "immunology" , "Mona" ,
			  "Mona" , 25 , 1 , 0 },{"Wednesday" , 23, 9 , 2023 ,4,0 , 30 ,"immunology" , "mariam" ,
			  "mariamm" , 30 , 1 , 0 } } , "mohannad" ,"mohannad_756"}, 55, 6, "mohannad_756",
			  "1234", "email1@example.com", "01234567891", 0, {}, 1, 0, 180},



			   {0,'f',"chloe", "malek",
			 "Nephrology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"chloe_66",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},


			   {0,'m',"dani", "ramez",
			   "immunology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"dani_99",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},



			   {0,'f',"gamella", "othman",
			  "Hematology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"gamelaaaaa_45",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},


			   {0,'f',"haneen", "Attya",
			  "Medical examiner",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"Haneen_27",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},


			   {0,'f',"Isis", "farok",
			   "Genital pathology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"Isis_45",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},


			   {0,'m',"karma", "akabane",
			  "Gastroenterology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"karma_87",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},


	


			   {0,'m',"Osman", "ramy",
			  "Endocrinology",10,3, {{"Saturday", 3,0,5,0,30,4,{{3,0,3,30,1,0,0},
			   {3,30,4,0,0,0,0},{4,0,4,30,0,0,0},{4,30,5,0,1,0,0}}},{},{},{"Tuesday", 4,0,7,0,30,6,{{4,0,4,30,1,0,0},{4,30,5,0,1,0,0},
			   {5,0,5,30,0,0,0},{5,30,6,0,0,0,0},{6,0,6,30,0,0,0},{6,30,7,0,1,0,0}}},{},{},{}},{},35,2,"Osman_DOC",
			   "1234","email1@example.com","01234567891",0,{},1.2,0,100},




	};
	pat patient[size_of_arrs] = {
	   { "Mona" , "1234" , "Mona" , "kamal" , 25 , 0 , 8 , 0 ,
	   { { 0 , { "Saturday" , 20 , 5 , 2023 ,2,0 , 30 , "Anesthesiology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 } ,  "nouran" , "nour"},{0,{ "Saturday" , 27 , 5 , 2023 ,4,0 , 30 , "Cardiology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 },  "Hassan" , "hassan12"},{0,{ "Monday" , 4 , 9 , 2023 ,4,0 , 30 , "Hematology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 }, "amany" , "amany_12"},{0,{ "Saturday" , 20 , 8 , 2023 ,12,0 , 30 , "immunology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 },"mohannad" ,"mohannad_756"},{ 0 , { "Saturday" , 20 , 1 , 2023 ,2,0 , 30 , "Anesthesiology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 } ,  "nouran" , "nour"},{0,{ "Saturday" , 27 , 1 , 2023 ,4,0 , 30 , "Cardiology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 },  "Hassan" , "hassan12"},{0,{ "Monday" , 4 , 9 , 2022 ,4,0 , 30 , "Hematology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 }, "amany" , "amany_12"},{0,{ "Saturday" , 20 , 8 , 2022 ,12,0 , 30 , "immunology" , "Mona" ,
	   "Mona" , 25 , 1 , 0 },"mohannad" ,"mohannad_756"}},'f'},
	   { "mariamm" , "1234" , "mariam" , "Ahmed" , 30 , 0 , 3 , 3 ,
		   {{ 0,{ "Saturday" , 27, 5 , 2023 ,3,0 , 30 , "Anesthesiology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "nouran" , "nour"}, { 0,{"Thursday" , 7, 9 , 2023 ,3,0 , 30 ,"Hematology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "amany" , "amany_12"},{ 0,{"Wednesday" , 23, 9 , 2023 ,4,0 , 30 ,"immunology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "mohannad" ,"mohannad_756"}},

		  {{ 0,{ "Saturday" , 27, 2 , 2023 ,3,0 , 30 , "Anesthesiology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "nouran" , "nour"}, { 0,{"Thursday" , 7, 3 , 2023 ,3,0 , 30 ,"Hematology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "amany" , "amany_12"},{ 0,{"Wednesday" , 23, 9 , 2022 ,4,0 , 30 ,"immunology" , "mariam" ,
	   "mariamm" , 30 , 1 , 0 }, "mohannad" ,"mohannad_756"}},'f'},



	   { "nehal12" , "1234" ,  "nehal" , "ramy" , 32 , 0 , 2 , 2 ,
		   { {0,  { "Wednesday" , 24, 5 , 2023 ,2,30 , 25 , "Cardiology" , "nehal" ,
	   "nehal12" , 32 , 1 , 0 } ,  "mariam" , "mariam"},{0,{ "Tuesday" , 27, 8 , 2023 ,5,0 , 30 , "Dermatology" , "nehal" ,
	   "nehal12" , 32 , 1 , 0 } ,"Hassan" ,"hassan12"}},

		  { {0,  { "Wednesday" , 24, 5 , 2022 ,2,30 , 25 , "Cardiology" , "nehal" ,
	   "nehal12" , 32 , 1 , 0 } ,  "mariam" , "mariam"},{0,{ "Tuesday" , 27, 1 , 2023 ,5,0 , 30 , "Dermatology" , "nehal" ,
	   "nehal12" , 32 , 1 , 0 } ,"Hassan" ,"hassan12"}},'f'},


		 { "ramadan_123" , "1234" ,  "ramdan" , "fawzy" , 25 , 0 , 2 , 2 ,
		   { { 0 ,  { "Tuesday" , 1 , 6 , 2023 ,6,0 , 30 , "Dermatology" , "ramdan" ,
	   "ramadan_123" , 25 , 1 , 0 } ,"Hassan" ,"hassan12"}, { 0 ,{ "Monday" , 19 , 6 , 2023 ,3,30 , 30 , "Cardiology" , "ramadan" ,
	   "ramadan_123" , 25 , 1 , 0 } ,"hoda" ,"hoda123"}},

	   { { 0, { "Tuesday" , 1 , 6 , 2022 ,6,0 , 30 , "Dermatology" , "ramdan" ,
	   "ramadan_123" , 25 , 1 , 0 }, "Hassan", "hassan12"}, { 0 ,{ "Monday" , 19 , 6 , 2021 ,3,30 , 30 , "Cardiology" , "ramadan" ,
	   "ramadan_123" , 25 , 1 , 0 } ,"hoda" ,"hoda123" }} ,'m'},


		   { "chloe_123" , "1234" , "chloe" , "bonjour" , 30 , 0 , 2 , 2 ,
			{{ 0 ,{"Thursday" , 6, 7 , 2023 ,3,30 , 30 , "Cardiology" , "chloe" ,
		   "chloe_123" , 30 , 1 , 0 }, "hoda", "hoda123"},{0,{ "Monday" , 31 , 7 , 2023 ,5,0 , 30 , "Endocrinology" , "chloe" ,
		"chloe_123" , 30 , 1 , 0 }, "Aoad" ,"Aoda_12"}},

		   {{ 0 ,{"Thursday" , 6, 7 , 2021 ,3,30 , 30 , "Cardiology" , "chloe" ,
		   "chloe_123" , 30 , 1 , 0 }, "hoda", "hoda123"},{0,{ "Monday" , 31 , 2 , 2023 ,5,0 , 30 , "Endocrinology" , "chloe" ,
		   "chloe_123" , 30 , 1 , 0 }, "Aoad" ,"Aoda_12"}},'f'},


		   {"karen_123" , "1234" , "karen" , "mitcho" , 30 , 0 , 1 , 1 ,
		   {0,{"Tuesday" ,22, 8 , 2023 ,4,30 , 30 , "Endocrinology" , "karen" ,
		"karen_123" , 30 , 1 , 0 }, "Aoad", "Aoda_12"},

		   {0,{"Tuesday" ,22, 8 , 2022 ,4,30 , 30 , "Endocrinology" , "karen" ,
		  "karen_123" , 30 , 1 , 0 }, "Aoad", "Aoda_12"},'f'}

	};
	doc suitable_doctor[15];
	int session[4] = { 15,30,45,60 };
	int last_doc_array = 14; // to know how much of the array is taken. for register. DEPENDS ON DATA
	int last_patient_array = 7;
	int current_doctor = 0, current_patient = 0;
	bool Log_out = 0;
	//input_data(doctor, patient, last_doc_array, last_patient_array);
	// arrange( docror);
	// TIME();
	leap_year(tmp->tm_year);
	History_list(patient, current_patient, doctor, last_doc_array);
	/*Sleep(5000);
	system("CLS");
	Sleep(1000);
	welcome();*/

	do
	{

		system("CLS");
		if (Login_and_Register(doctor, current_doctor, patient, current_patient, last_doc_array, last_patient_array))
		{
			TIME();
			Patient_Homepage(patient, current_patient);
			Log_out = Patient_Modes(patient, current_patient, doctor, suitable_doctor, last_doc_array);
		}
		else
		{
			TIME();
			Doctor_Homepage(doctor, current_doctor);
			Log_out = Doctor_Modes(doctor, current_doctor, patient, last_patient_array, session);

		}

		//save_data(doctor, patient, last_doc_array, last_patient_array);

	} while (Log_out);

	return 0;
}
