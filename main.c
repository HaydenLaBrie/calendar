#include <stdio.h>
int is_leap_year(int);
int days_of_year(int);
int position_of_month(int, int);
void print_calendar(int, int);

int main() {
    print_calendar(2000,1);
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
    char dayarr [][10] ={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int start = position_of_month(year, month); //what day the first day should be
    int days = 0;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        days = 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if(is_leap_year(year))
        days = 29;
    else
        days = 30;
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
    int numbs[5][7]; //Need to make a 2d array that covers 0 - 31 and is formatted correctly, then I can make if statements to have it match right
    while(i < days){
        i++;
    }
}

