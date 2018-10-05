#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>

using namespace std;

class Box // making an object BOX.
{
    int length;
    int width;
    int height;
    int volume;

public:

    Box()
    {
        width;
        height;
        length;
    }

    void Length()
    {
         length = 5 + (rand() % 25); //Length of the box
    }

    int get_length()
    {
        return length;
    }

    void Width()
    {
         width  = 5 + (rand() % 25); //width of the box
    }
    int get_width()
    {
        return width;
    }

    void Height()
    {
        height = 5 + (rand() % 25); // Height of the box
    }
    int get_height()
    {
        return height;
    }

    void Volume()
    {
        volume = length * width * height; //Calculating Volume of the box.
    }

    int get_volume()
    {
        return volume; // Returning the volume of the box.
    }
};

class Truck
{
    char driver[32];
    int petrol;
    int money;
    int FullMileage;
    int emptyMileage;
    float total_journey;
    float cost_per_litre;
    float max_petrol;
    Box *array_box; // Dynamic array for boxes.

public: // All public functions for class truck.

    Truck()
    {
        total_journey  = 60; // distance to be covered in the journey.
        cost_per_litre = 2.73; // cost per liter for fuel.
        max_petrol     = 50; // Truck's fuel tank capacity.
    }

    void set_driver(char d[32]) // Extracts the name of the driver from main function and stores it here.
    {
        strcpy(driver, d); //character array d is copied to driver.
    }

    string get_driver() //returns the name of the driver.
    {
        return driver;
    }

    void set_petrol(int fuel) //Access the value of petrol in a respective truck from main function and sets it here.
    {
        petrol = fuel;
    }

    int get_petrol() // Return the value of petrol present in a respective truck.
    {
        return petrol;
    }

    void set_money(int m) // Extracts the amount of money a driver has from the main and set it here.
    {
        money = m;
    }

    int get_money() // returns the amount of money the driver has.
    {
        return money;
    }
    void set_e_mileage(int e_mileage) // Extracts the value of empty mileage of a truck from the main function and sets here.
    {
        emptyMileage = e_mileage;
    }

    int get_e_mileage() //returns the value of the mileage when the truck is empty.
    {
        return emptyMileage;
    }

    void set_f_mileage(int f_mileage) //extracts the value of mileage when the truck is full from the main and sets is here.
    {
        FullMileage = f_mileage;
    }

    int get_f_mileage() // returns the value of mileage of the truck when the truck is full.
    {
        return FullMileage;
    }

    int checker() //This function checks whether the the truck enough money to go for the delivery or not.
    {
        int fuel_needed;
        float required_money;
        if(petrol < 50) // Check the current status of the fuel tank; whether the the tank has petrol less than 50 litres.
        {
            fuel_needed = max_petrol-petrol; // calculates the amount of petrol needed to full the truck's tank.
            required_money =  fuel_needed * cost_per_litre; // calculates the amount of money to full the fuel tank.
            if(required_money > money) // check whether the driver has enough money to full the tank. if the required money is great than it tell the  how much amount more do the driver need to fill the tank.
            {
                cout<<"Money needed is $"<< required_money << ". The driver currently has $ "<<money<<endl;
                return 0;
            }
            else // The driver has enough cash to start his  journey.
            {
                petrol = petrol + fuel_needed; // Tank is full t 50 liters.
                cout<<"\nMoney needed is $"<< required_money << ". The driver currently has $ "<<money<<endl;
                money = money - required_money; //the money is reduced to the amount left after spending on petrol.
                return 1;
            }

         }
         return 0;
    }

    float petrol_left() //returns the amount of petrol left
    {
        float fuel_left;
        fuel_left = 50 - ((60/FullMileage)+ (60/emptyMileage)); // calculates how  much liters the petrol is left in the truck after the completion of journey.
        return fuel_left;
    }


    void print() //Prints the details of driver and the truck.
    {
        cout<<"\n ****Driver can start the journey!****"<<endl;
        cout<<"Driver's New Details:"<<endl;
        cout<<"Driver's Name:"<<driver<<endl;
        cout<<"Truck's fuel:"<<petrol<<endl;
        cout<<"Money Driver has:"<<money<<endl;
        cout<<"Truck's Empty Mileage:"<<emptyMileage<<endl;
        cout<<"Truck's Loaded Mileage:"<<FullMileage<<endl;
    }

    void Load(int numBox) // Loads boxes in the truck.
    {
        array_box = new Box[numBox];
        for(int i=0; i<numBox;i++)
        {
            Box box;
            box.Volume();
            box.Width();
            box.Height();
            box.Length();
            array_box[i] = box;
            cout << "\nVolume of the box"<<i+1<<":" <<array_box[i].get_volume()<<"inches cube"<<endl;
            cout << "length of the box"<<i+1<<":" <<array_box[i].get_length()<<"inches"<<endl;
            cout << "width of the box"<<i+1<<":" <<array_box[i].get_width()<<"inches"<<endl;
            cout << "height of the box"<<i+1<<":" <<array_box[i].get_height()<<"inches"<<endl;
        }

    }
    void Unload() //Unloading the boxes from the truck.
    {
        delete[] array_box;
    }


    float Cost() //returns the total cost spent on the delivery journey.
    {
        float loaded_cost, empty_cost, total_cost;

        loaded_cost = (total_journey/FullMileage)*cost_per_litre;
        empty_cost  = (total_journey/emptyMileage) * cost_per_litre;
        total_cost = loaded_cost + empty_cost;

        return total_cost;
    }

     float money_left() // returns the value of money left after the completion of the journey.
    {
        float m_left;
        m_left = money - Cost();

        return m_left;

    }
};

int LineCounter(const char* fileName)
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}

int main()
{
    srand(time(0));
    FILE* filePointer;     //Declaring a file pointer


    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only
    int counter = LineCounter("Drivers.txt");
    int counter_1 = counter / 5;

    Truck *array_truck;

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    ofstream myfile; // Creating a file.
    myfile.open("trips.txt"); // Creating and opening the file Trips.txt.

    array_truck = new Truck[counter_1];

    myfile<<"**************************TRUCK PACKAGE DELIVERY SYSTEM***********************************"<<endl;

    for(int i=0;i<counter_1;i++)
    {
        Truck ural;
        char buff[32];      //Declaring a character array to store a line

        fgets(buff, 32, (FILE*)filePointer);//Reading the name of the driver directly
        ural.set_driver(buff);

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        ural.set_petrol(atoi(buff));                   //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        ural.set_money(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.set_e_mileage(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.set_f_mileage(atoi(buff));


        myfile << "Truck driver is: " << ural.get_driver()<<endl;
        myfile <<"Truck petrol is: " << ural.get_petrol()<<endl;
        myfile <<"Truck money is: " << ural.get_money()<<endl;                      // Drivers' and trucks' updated details.
        myfile <<"Truck empty mileage is: " << ural.get_e_mileage()<<"km"<<endl;
        myfile <<"Truck full mileage is: " << ural.get_f_mileage()<<"km"<<endl;

        int No_of_boxes = 12 + (rand()%9); // generating number of boxes randomly ranging from 12-20.

        if(ural.checker() == 1)  //Checks if the driver is good to go.
        {
            ural.print();
            myfile <<No_of_boxes<<"packages are being loaded on the truck: \n"<<endl;
            ural.Load(No_of_boxes);
            ural.Unload();
            myfile <<"Truck is empty!"<<endl;
            myfile <<"Total Cost of the journey is: "<<ural.Cost()<<endl;
            myfile <<"Petrol left after the journey: " <<ural.petrol_left()<<"litres."<<endl;
            myfile <<"Money left after the journey: $"<<ural.money_left()<<endl;
            myfile<<endl;
        }
        else
        {
            myfile<<"\nJourney cannot be continued \n"<<endl;
        }
        array_truck[i] = ural;
    }
    delete[] array_truck;    //deallocating the box array.
    fclose(filePointer);                        //Closing file
    return 0;
}
