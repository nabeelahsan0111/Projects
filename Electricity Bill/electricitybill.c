#include <stdio.h>
#include <ctype.h>
void display(char id[],double unit,char cat[],char c,double init_bill,double srvc,double total,double mtr){
    printf("////////////////////////////////////////////////     ELECTRICITY BILL    //////////////////////////////////////////////////////\n\n");
    printf("===============================================================================================================================\n");
    printf("CUSTOMER ID : %s\t\tCUSTOMER CATEGORY %c : %s\n",id,c,cat);
    printf("===============================================================================================================================\n\n");
    printf("CONSUMED UNIT \t INTIAL-BILL \t SERVICE-CHARGE \t MERTER CHARGE  \t METER REPLACE CHARGE/CHANGE-CHARGE \t FINAL-CHARGE\n\n");
    printf("%0.2f\t\t %0.2f\t  %0.2f\t\t\t  %0.2f\t\t\t %0.2f\t\t\t\t\t  %0.2f\n",unit,init_bill,srvc,50.00,mtr,total);
    printf("===============================================================================================================================\n\n");
}
void residential(char id[],double unit,char r){
    int opt;
    char optt[10];
    printf("ARE YOU LIFE LINE CUSTOMER(YES/NO) : ");
    scanf("%s",optt);
    if(toupper(optt[0]) == 'Y'){
        double bill=unit*3.33;
        int phase;
        double service_chrg;
        printf("ENTER THE METER PHASE(1/3) : ");
        scanf("%d",&phase);
        if(phase == 1){
            service_chrg = 10.00;
        } 
        else{
            service_chrg = 30.00;
        }
        double meter_rep;
        if(toupper(r) == 'Y'){
            meter_rep = 2000.00;
        }
        else{
            meter_rep = 0.0;
        }
        display(id,unit,"RESIDENTIAL",'A',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep);
    }
    else{
        double bill;
        if(unit>=0 && unit<=75){
            bill = unit*3.80;
        }
        else if(unit>=76 && unit<=200){
            bill = unit*5.14;
        }
        else if(unit>=201 && unit<=300){
            bill = unit*5.36;
        }
        else if(unit>=301 && unit<=400){
            bill = unit*5.63;
        }
        else if(unit>=401 && unit<=600){
            bill = unit*8.70;
        }
        else{
            bill = unit*9.98;
        }
        int phase;
        double service_chrg;
        printf("ENTER THE METER PHASE(1/3) : ");
        scanf("%d",&phase);

        
        if(phase == 1){
            service_chrg = 10.00;
        } 
        else{
            service_chrg = 30.00;
        }
        double meter_rep;
        if(toupper(r) == 'Y'){
            meter_rep = 2000.00;
        }
        else{
            meter_rep = 0.0;
        }
        display(id,unit,"RESIDENTIAL",'A',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep);
    }
}
void agriculturalpumping(char id[],double unit,char r){
    double bill=unit*3.82;
    double service_chrg=30.00;
    double meter_rep;
    if(toupper(r) == 'Y'){
        meter_rep = 2000.00;
    }
    else{
        meter_rep = 0.0;
    }
    display(id,unit,"AGRICULTURAL PUMPING",'B',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep);
}
void smallindustries(char id[],double unit,char r){
    int opt;
    double bill;
    printf("CHOOSE :\n (1) FLAT RATE \n (2) OFF-PEAK TIME \n (3) PEAK TIME \nOPTION : ");
    scanf("%d",&opt);
    if(opt == 1){
        bill = unit*7.66;
    }
    else if(opt == 2){
        bill = unit*6.90;
    }
    else if(opt == 3){
        bill = unit*9.24;
    }
    double service_chrg=70.00;
    double meter_rep;
    if(toupper(r) == 'Y'){
        meter_rep = 2000.00;
    }
    else{
        meter_rep = 0.0;
    }
    display(id,unit,"SMALL INDUSTRIES",'C',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep);
}
void nonindustrial(char id[],double unit,char r){
    int phase;
    double service_chrg;
    printf("ENTER THE METER PHASE(1/3) : ");
    scanf("%d",&phase);

     
    if(phase == 1){
        service_chrg = 10.00;
    } 
    else{
        service_chrg = 30.00;
    }

    double bill = unit*5.22;
    double meter_rep;
    if(toupper(r) == 'Y'){
        meter_rep = 2000.00;
    }
    else{
        meter_rep = 0.0;
    }
    display(id,unit,"NON INDUSTRIAL",'D',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep); 
}
void commercialandoffice(char id[],double unit,char r){
    int opt;
    double bill;
    printf("CHOOSE :\n (1) FLAT RATE \n (2) OFF-PEAK TIME \n (3) PEAK TIME \nOPTION : ");
    scanf("%d",&opt);
    if(opt == 1){
        bill = unit*9.80;
    }
    else if(opt == 2){
        bill = unit*8.45;
    }
    else if(opt == 3){
        bill = unit*11.98;
    }
    int phase;
    double service_chrg;
    printf("ENTER THE METER PHASE(1/3) : ");
    scanf("%d",&phase);

     
    if(phase == 1){
        service_chrg = 10.00;
    } 
    else{
        service_chrg = 30.00;
    }
    double meter_rep;
    if(toupper(r) == 'Y'){
        meter_rep = 2000.00;
    }
    else{
        meter_rep = 0.0;
    }
    display(id,unit,"COMMERCIAL AND OFFICE",'E',bill,service_chrg,(bill + service_chrg + meter_rep + 50),meter_rep);
}


int main()
{
    char customer_id[20],customer_category[10],replace[10];
    double metercharge = 50;
    // start:
    printf("ENTER CUSTOMER ID : ");
    scanf("%s",customer_id);
    printf("\n\nCATEGORY A : RESIDENTIAL\nCATEGORY B : AGRICULTURAL PUMPING\nCATEGORY C : SMALL INDUSTRIES\nCATEGORY D : NON-RESIDENTIAL\nCATEGORY E : COMMERCIAL AND OFFICE\n\nENTER THE CUSTOMER CATEGORY :");
    scanf("%s",customer_category);
    char c = toupper(customer_category[0]);
    printf("ENTER CONSUME UNIT : ");
    double consumed_unit;
    scanf("%lf",&consumed_unit);
    printf("DO YOU WANT TO CHANGE OR REPLACE YOUR METER(YES/NO) : ");
    scanf("%s",replace);
    switch (c)
    {
    case 'A':
        residential(customer_id,consumed_unit,replace[0]);
        break;
    case 'B':
        agriculturalpumping(customer_id,consumed_unit,replace[0]);
        break;
    case 'C':
        smallindustries(customer_id,consumed_unit,replace[0]);
        break;
    case 'D':
        nonindustrial(customer_id,consumed_unit,replace[0]);
        break;
    case 'E':
        commercialandoffice(customer_id,consumed_unit,replace[0]);
        break;
    default:
        printf("WRONG CATEGORY.TRY AGAIN !\n");
        // goto start;
        break;
    }
    return 0;
}