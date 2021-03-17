#include <iostream>
#include <stdexcept>
#include <string>
#include "snowman.hpp"
using namespace std;
        const int ten = 10; //for dviding the int fer digits
        const int zero = 0;//HAT
        const int one = 1;// Nose
        const int two = 2;// Left eye
        const int three = 3;//  Right eye
        const int four = 4;// Left hand 
        const int five = 5;// Right hand
        const int six = 6;// Belly
        const int seven = 7;// Base
        const int eight = 8;//for compering

namespace ariel{
        
      
    void throwException(){
        throw invalid_argument("Invalid code");
    }
    //Input - number - must be 8 digits between 1-4 each digit
    //Output - snow man
    string makeHat(char hat){
        string Hat=" ";
        switch (hat){
            case '1': Hat= "_===_";
            break;
            case '2': Hat= " ___ \n .....";
            break;
            case '3': Hat= "  _  \n  /_\\";
            break;
            case '4': Hat= " ___\n (_*_)";
            break;
        }
        return Hat+"\n";
        }
    string makeHead(char nose,char Leye,char Reye){
        string face="(";
        switch (Leye){
            case '1': face+= '.';
            break;
            case '2': face+= 'o';
            break;
            case '3': face+= 'O';
            break;
            case '4': face+= '-';
            break;
        }
         switch (nose){
            case '1': face+= ',';
            break;
            case '2': face+= '.';
            break;
            case '3': face+= '_';
            break;
            case '4': face+= ' ';
            break;
        }
          switch (Reye){
            case '1': face+='.';
            break;
            case '2': face+='o';
            break;
            case '3': face+='O';
            break;
            case '4': face+='-';
            break;
        }
        face+=")";
        return  face;
        }
    string topMiddle(char Lhand,char Rhand, char belly){
        string innertop=" ";
          switch (Lhand){
            case '1': innertop= "\n<";
            break;
            case '2': innertop= "";
            break;
            case '3': innertop= "\n/";
            break;
            case '4': innertop= "";
            break;
        }
        innertop+="(";
          switch (belly){
            case '1': innertop+= " : ";
            break;
            case '2': innertop+= "] [";
            break;
            case '3': innertop+= "> <";
            break;
            case '4': innertop+= "   ";
            break;
        }
        innertop+=")";
          switch (Rhand){
            case '1': innertop+= ">";
            break;
            case '2': innertop+= "";
            break;
            case '3': innertop+= "\\";
            break;
            case '4': innertop+= " ";
            break;
        }
        
        return  innertop+"\n";
    }
    string makeBase(char base){
        string top=" ";
        switch (base){
            case '1': top= "( : )";
            break;
            case '2': top= "(\" \")";
            break;
            case '3': top= "(___)";
            break;
            case '4': top= "(   )";
            break;
        }
        return top;
    }


        string snowman(int input){
        string output=  to_string(input);//int -> string
        int counter = 0;
        if(input< 0){
            throwException();
        }
     
        while( input != 0){
            int digit = input % ten;
            if(digit <one || digit > four){
                throwException();
                //cout <<"Wrong Input Optional<1-4 acceptable>"<< endl;
            }
            input = input/ten;
            counter++;
        }
        if(counter != eight){
            throwException();
        }
        string Drawsnoman;
        string Hat;
        string head;
        string belly;
        string base;
        if (output[4] == '4'){
         Hat = " " + makeHat(output[zero]);
         head = " " +makeHead(output[one],output[two],output[three]);
         belly = "\n " + topMiddle(output[four],output[five],output[six]);
         base = " " + makeBase(output[seven]);
        }
        else if(output[4] == '2'){
            Hat = makeHat(output[zero]);;
            head = makeHead(output[one],output[two],output[three]);
            belly ="\n " +topMiddle(output[four],output[five],output[six]);
            base =  makeBase(output[seven]);
        }
        else{// '<','/'
            Hat = " " + makeHat(output[zero]);;
            head = " " + makeHead(output[one],output[two],output[three]);
            belly =  topMiddle(output[four],output[five],output[six]);
            base = " " + makeBase(output[seven]);
        }
        //check left up arm:
        if (output[four] == '2'){
            Hat = " " + Hat;
            head = "\\" + head;
            belly = " " + belly;
            base = " " + base;
        }
        //check right up arm:
        if (output[five] == '2'){
            head = head+ "/";
        } 


        Drawsnoman=Hat+head+belly+base;

    return Drawsnoman;
 }

}
