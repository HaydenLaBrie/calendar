#include <stdio.h>
int is_leap_year(int);
int days_of_year(int);
int position_of_month(int, int);
void print_calendar(int, int);
void print_numbers(int, int);

int main() {
    printf("Enter year: ");
    int year;
    scanf("%d", &year);
    printf("Enter month: ");
    int month;
    scanf("%d", &month);
    print_calendar(year,month);
    return 0;
}

int is_leap_year(int year){
    if((year % 4 == 0) && (year % 100 != 0)){
        return 1;
    }
    if((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0)){
        return 1;
    }
    else
        return 0;
}

int days_of_year(int year){
    if(is_leap_year(year) == 1){
        return 366;
    }
    else
        return 365;
}

int position_of_month(int year, int month){
    int i = year - 2000; // how many more years greater than 2000
    int leap_check = 2000; //we start at 2000 to see how many days are during that year to calculate how many days are needed from Jan 1, 2000 to Jan 1, 20001
    //We say one day is the transition from one day to another. Example: Tuesday is 1 day different than Monday. Wednesday is 2 days different than Monday.
    //We know that if year 2000 has n days, then we can say it has n-1 days from Jan 1st, thus to get to jan 1st of next year will be (n-1)+1 = n
    int days = 0;
    int position; //used to state the position of the first day of the month
    while(i != 0){ //This loop is to find how many days is that years jan 1st from jan 1st 2000
        days = days + days_of_year(leap_check);
        leap_check++;
        i--;
    }
    if(month > 1){
        days = days + 31; // feb 1st is 31 more days than jan 1st
        if(month > 2){
            if(is_leap_year(year)){
                days = days + 29;
            }
            else
                days = days + 28;
        }
        if(month > 3)
            days = days + 31;
        if(month > 4)
            days = days + 30;
        if(month > 5)
            days = days + 31;
        if(month > 6)
            days = days + 30;
        if(month > 7)
            days = days + 31;
        if(month > 8)
            days = days + 31;
        if(month > 9)
            days = days + 30;
        if(month > 10)
            days = days + 31;
        if(month > 11)
            days = days + 30;
        position = days % 7;
        return position;
    }
    else{ // its jan
        position = days % 7;
        return position;
    }
}

void print_calendar(int year, int month){
    char montharr [][12] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char dayarr [][10] ={" Sunday  ", " Monday  ", " Tuesday ", "Wednesday", "Thursday ", " Friday  ", "Saturday "};
    int start = position_of_month(year, month); //what day the first day should be
    int days = 0;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        days = 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if(is_leap_year(year))
        days = 29;
    else
        days = 28;
    int x = 0;
    while(x < 40){
        printf(" ");
        x++;
    }
    printf("%d\n", year);
    x = 0;
    while(x < 38){
        printf(" ");
        x++;
    }
    printf("%s\n", *(montharr + (month - 1)));
    int i = 0;
    while(i < 7){ //wordsize + 2; example Monday word count is 6 + 2 = 8, thus gets 8 spaces.
        if(i == 6){
            printf(" %s", dayarr[i]);
        }
        else{
            printf(" %s |", dayarr[i]);
        }
        i++;
    }
    printf("\n");
    print_numbers(start, days);
}

void print_numbers(int start, int days){
    char numbs [][3]={"01","02","03","04","05","06","07", "08", "09", "10",
                      "11", "12", "13", "14", "15", "16", "17", "18", "19",
                      "20", "21", "22", "23", "24", "25", "26", "27", "28",
                      "29", "30", "31"};
    int j = 0;
    if(start == 0)
        start = 7;
    int i = start - 1;
    while(i > 0){
        printf("            "); //12 spaces
        i--;
    }
    i = start - 1;
    while(days > 0){
        while(i < 7 && days != 0){
            printf("    %s      ", *(numbs + j));
            days--;
            i++;
            j++;
        }
        i = 0;
        printf("\n");
    }
}

