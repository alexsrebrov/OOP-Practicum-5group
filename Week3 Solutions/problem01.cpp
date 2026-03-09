#include<iostream>

const int MAX_HOUR=24;
const int MAX_MINUTE=60;
const int MAX_SECOND=60;
const int SECONDS_IN_HOUR=3600;
const int SECONDS_IN_MINUTE=60;
const int MIDNIGHT=24;

class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time() {
        hours=0;
        minutes=0;
        seconds=0;
    }

    int timeToSeconds() {
        int total=0;
        total+=hours*SECONDS_IN_HOUR;
        total+=minutes*SECONDS_IN_MINUTE;
        total+=seconds;
        return total;
    }

    void sortTime() {
        if (seconds>=MAX_SECOND) {
            minutes+=seconds/MAX_SECOND;
            seconds%=MAX_SECOND;

        }
        if (minutes>=MAX_MINUTE) {
            hours+=minutes/MAX_MINUTE;
            minutes%=MAX_MINUTE;
        }
        if (hours>=MAX_HOUR) {
            hours%=MAX_HOUR;
        }
    }

    void secondsToTime() {
        hours=seconds/SECONDS_IN_HOUR;
        seconds%=SECONDS_IN_HOUR;
        minutes=seconds/SECONDS_IN_MINUTE;
        seconds%=SECONDS_IN_MINUTE;
    }

    Time(int hours,int minutes,int seconds) : hours(hours),minutes(minutes),seconds(seconds){
        if (hours>=MAX_HOUR || minutes>=MAX_MINUTE || seconds>=MAX_SECOND) {
            this->hours=0;
            this->minutes=0;
            this->seconds=0;
        }
    }

    void printTime()  {
        this->sortTime();
        if (hours<10) {
            std::cout<<"0"<<hours<<":";
        }
        else {
            std::cout<<hours<<":";
        }
        if (minutes<10) {
            std::cout<<"0"<<minutes<<":";
        }
        else {
            std::cout<<minutes<<":";
        }
        if (seconds<10) {
            std::cout<<"0"<<seconds;
        }
        else {
            std::cout<<seconds;
        }
        std::cout<<std::endl;
    }

    void addASecond() {
        seconds+=1;
        sortTime();
    }

    Time timeRemainingToMidnight() {
        Time remaining;
        remaining.seconds=MIDNIGHT*SECONDS_IN_HOUR-this->timeToSeconds();
        remaining.secondsToTime();
        return remaining;
    }

    bool dinnerTime() {
        Time start(20,30,0);
        Time end(22,0,0);

        return this->timeToSeconds()>=start.timeToSeconds() && this->timeToSeconds()<=end.timeToSeconds();
    }

    bool partyTime() {
        Time start(23,0,0);
        Time end(6,0,0);

        return this->timeToSeconds()>=start.timeToSeconds() || this->timeToSeconds()<=end.timeToSeconds();
    }

    Time differenceBetweenTwoTimes(Time& t) {
        Time difference;
        if (this->timeToSeconds()>t.timeToSeconds()) {
            difference.seconds=this->timeToSeconds()-t.timeToSeconds();
        }
        else {
            difference.seconds=t.timeToSeconds()-this->timeToSeconds();
        }
        difference.secondsToTime();
        return difference;
    }

    void isItBeforeOrAfter(Time& t) {
        if (this->timeToSeconds()>t.timeToSeconds()) {
           std::cout<<"After"<<std::endl;
        }
        else {
           std::cout<<"Before"<<std::endl;
        }
    }

};

int main() {
   Time times[10]={
       Time(13, 5, 45),
       Time(23, 15, 10),
       Time(6, 30, 0),
       Time(20, 45, 5),
       Time(7, 0, 1),
       Time(18, 20, 30),
       Time(22, 0, 0),
       Time(11, 11, 11),
       Time(5, 59, 59),
       Time(14, 50, 25)
   };
   for (int i=0; i<10; ++i) {
       for (int j=0; j<9-i; ++j) {
           if (times[j].timeToSeconds()>times[j+1].timeToSeconds()) {
               std::swap(times[j],times[j+1]);
           }
       }
   }
   for (int i=9; i>=0; --i) {
       times[i].printTime();
   }
}