
#include <stdio.h>
#include <string.h>

#define MAX_TUTORS 7
#define MAX_STUDENTS 7
#define MAX_SESSIONS 5


#define MAX_TITLE_LENGTH 50
#define MAX_DAY_LENGTH 10
#define MAX_LOCATION_LENGTH 10
#define MAX_PW 20
#define MAX_ATTEMPTS 5

// STRUCT = user-defined composite
		//easier to read
		struct Tutor {
			char Tutor_name[50];
			char TutorID[10];
			char Tutor_pw[50];
		};

		struct Student {
			char Student_name[50];
			char StudentID[10];
			char Student_pw[50];
		};

		struct user {
			char usertype[10];
			char userID[10];
			char username[50];
			char user_pw[20];
		} users;

		struct Session {
			char Session_code[5];
			char Session_name[MAX_TITLE_LENGTH + 1];
			char Session_day[MAX_DAY_LENGTH + 1];
			char Session_time[10];
			char Session_location[MAX_LOCATION_LENGTH + 1];
			struct Tutor tutor;
			struct Student students[MAX_STUDENTS];
			int student_num;
		};
        
		struct Tutor tutors[MAX_TUTORS];
		struct Student students[MAX_STUDENTS];
		struct Session sessions[MAX_SESSIONS];

int aliabu() {
	if (fopen("tutors.txt", "r") == NULL) {
		FILE* tutor_file;
		tutor_file = fopen("tutors.txt", "w");
		if (tutor_file == NULL) {
			printf("~~~~~~~Error open file!!~~~~~~~");
			return 0;
		}
		else {
			fprintf(tutor_file, "%s\n", "Tutor ID \t|| Name \t|| Title\n T01 \t\t|| Albert \t|| Web Development\n T02 \t\t|| Amad \t|| C Sharp Programming\n T03 \t\t|| Steve \t|| Python Programming");
			fclose(tutor_file);
		}
	}
	if (fopen("student.txt", "r") == NULL) {
		FILE* student_file;
		student_file = fopen("student.txt", "w");
	}
	if (fopen("session.txt", "r") == NULL) {
		FILE* session_file;
		session_file = fopen("session.txt", "w");
		if (session_file == NULL) {
			printf("~~~~~~~Error open file!!~~~~~~~");
			return 0;
		}
		else {
			fprintf(session_file, "%s\n", "Session Code \t|| Title \t\t|| Day \t\t|| Start Time \t|| Location \t|| Tutor Code\n PYP101 \t|| Python Programming \t|| Saturday \t|| 9.00am \t|| C-01-01 \t|| T01\n JAV102 \t|| Java Programming \t|| Sunday \t|| 9.00am \t|| C-01-02 \t|| T02\n CPL103 \t|| C Programming \t|| Saturday \t|| 2.00pm \t|| C-01-03 \t|| T03\n WEB104 \t|| Web Development \t|| Sunday \t|| 2.00pm \t|| C-01-04 \t|| T04\n CSP105 \t|| C Sharp Programming \t|| Monday \t|| 7.00pm \t|| C-01-05 \t|| T05\n");
			fclose(session_file);
		}
	}
	return 0;
}

int main()
{	
    aliabu();
	struct user users;
	
    //Store users login data
	FILE* userlogin_file = fopen("userlogin.txt", "w");

    char userlogin[20][4][200] = {
    // {"Usertype","UserID","Username","User_pw"}
    {"admin","AD01","Rose","rosekim"},
    {"admin","AD02","Lisa","lisamonaban"},
    {"admin","AD03","Jisoo","jisookim"},
    {"tutor","T01","Albert","albertbp"},
    {"tutor","T02","Amad","amadbp"},
    {"tutor","T03","Steve","stevebp"},
    {"tutor","T04","Sireesha","sireeshabp"},
    {"tutor","T05","Siwa","siwabp"},
    {"student","S01","Abdullah","abdullahh"},
    {"student","S02","Yogeswaran","yogeswarann"},
    {"student","S03","Manwei","manweii"},
    {"student","S04","Jiaxin","jiaxinn"},
    {"student","S05","QiuZheng","qzhengg"}
    };

    //r=row, c=column
    for (int r=0; r<14; r++){
        for(int c=0; c<4; c++){
            fprintf(userlogin_file, "%s;", userlogin[r][c]);
        }
        fprintf(userlogin_file,"\n");
    };

    fclose(userlogin_file);
    
    //Start Login Page
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("                    LOGIN PAGE                     \n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    userlogin_file = fopen("userlogin.txt", "r");
    if (userlogin_file == NULL){
            printf("~~~~~~~ERROR TO OPEN FILE!!~~~~~~~");
            return 1;
    }
	
    int attempt_count = 0; //add features 1
    char userID[10];
    char user_pw[MAX_PW];

    while (attempt_count < MAX_ATTEMPTS){
        printf("UserID: ");
		scanf("%s",&userID);
        printf("User Password: ");
        scanf("%s",&user_pw);

        //Reset the file pointer to the begining of the file for every attempts
        rewind(userlogin_file);
        int found = 0;
       
        while (fscanf(userlogin_file, "%[^;];%[^;];%[^;];%[^;];%s", users.usertype, users.userID, users.username, users.user_pw) !=EOF) {
            if (strcmp(users.userID, userID) == 0 && strcmp(users.user_pw, user_pw) == 0) {
                found = 1;
                break;
            }
        }

        if (found = 1) {
			printf("\n\n=========================================\n");
            printf("//   Login successfully! Welcome, %s   //\n", users.username);
            printf("=========================================\n");
			break;
        } 
        else {
			printf("=======================================================\n");
            printf("XX   Invalid UserID or Password. Please try again.   XX\n");
			printf("=======================================================\n");

            attempt_count++;
        }
    }
    if (attempt_count == MAX_ATTEMPTS){
    printf("**     Your attempts has reach limits! Please try again later.\n     **");
    }
    
    fclose(userlogin_file);

    return 0;
    }















/*
		//Start another case here
		printf("\n(1) Registration New Tutor\n(2) Registration for Student\n(3) Add a new session\n(4) Enrol Student into a session\n(5) List session stduent enrolled\n(6) Exit\n");
		printf("\nWhich Function Number You Looking For? ~ ");
		scanf("%d", &choice_123);

	

		switch (choice_123) {
		case 1: //add new tutor
			FILE * tutor_file;
			//open file 
			tutor_file = fopen("tutors.txt", "a");
			if (tutor_file == NULL) {
				printf("Error open file!\n");
				return 1;
			}

			printf("\nEnter Tutor Name: ");
			scanf("%s", &tutors[tutor_num].Tutor_name);
			printf("Enter Tutor ID: ");
			scanf("%s", &tutors[tutor_num].TutorID);
			printf("Enter Tutor Password: ");
			scanf("%s", &tutors[tutor_num].Tutor_pw);
			printf("Enter Session Name: ");
			scanf("%s", &sessions[session_num].Session_name);

			//let data insert into file
			fprintf(tutor_file, " %s \t\t|| %s \t|| %s\n", tutors[tutor_num].TutorID, tutors[tutor_num].Tutor_name, sessions[session_num].Session_name);

			printf("\nTutor succesfully added!\n");
			tutor_num++;

			if (tutor_num >= max_tutors) {
				printf("Tutor limit is full, cannot add more!\n\n");
				break;
			}

			//close file
			fclose(tutor_file);
			break;

		case 2: // register for new student
			FILE * student_file;
			//OPEN FILE
			student_file = fopen("student.txt", "a");
			if (student_file == NULL) {
				printf("Error open file!\n");
				return 1;
			}
			while (student_num < max_student) {

				printf("Enter student name: ");
				scanf("%s", students[student_num].Student_name);
				printf("Enter student ID: TP");
				scanf("%s", students[student_num].StudentID);
				printf("Enter student password: ");
				scanf("%s", students[student_num].Student_pw);

				printf("\nStudent registered succesfully!\n");
				student_num++;

				if (student_num >= max_student) {
					printf("Student limit has reach, cannot add more!\n\n");
					break;
				}
			}
			//close file
			fclose(student_file);
			break;

		case 3: //add new session
			if (session_num >= max_session) {
				printf("\nSession reach the limit, cannot add more!!!!\n");
				return 1;
			}
			printf("Enter Session Code: ");
			scanf("%s", sessions[session_num].Session_code);
			printf("Enter Session Name: ");
			scanf("%s", sessions[session_num].Session_name);
			printf("Enter Session Day: ");
			scanf("%s", sessions[session_num].Session_day);
			printf("Enter Session start time: ");
			scanf("%s", sessions[session_num].Session_time);
			printf("Enter Session Location: ");
			scanf("%s", sessions[session_num].Session_location);

			//prompt admin to select tutor
			printf("Enter Tutor Code for the session: ");
			scanf("%s", sessions[session_num].tutor.TutorID);

			//find tutor in array
			int tutor_index = -1;
			for (int i = 0; i < tutor_num; i++) {
				if (strcmp(tutors[i].TutorID, sessions[session_num].tutor.TutorID) == 0) {
					tutor_index = i;
					break;
				}
			}
			if (tutor_index == -1) {
				printf("Tutor not found!\n");
				return 0;
			}

			printf("Session successfully added!\n\n");
			session_num++;
			break;

		case 4: //enroll student into session
			if (student_num == 0) {
				printf("No student enrolled!\n");
				break;
			}
			if (session_num == 0) {
				printf("No session avalable!\n");
				break;
			}
			printf("Enter enrolling Student ID: TP ");
			scanf("%s", StudentID);
			printf("Enter student enrol session code: ");
			scanf("%s", sessions[session_num].Session_code);


			break;

		case 5: //List all session student enrolled


		default:
			printf("\nInvalid choice!!\n");
			break;
		}
		break;
	}
    */
