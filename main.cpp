#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;


int main() {


        int lotto[6];
        bool unique;
        int user[6];
        int Counters[2][4]= {0};


        srand(time(0));
        cout << "----------------------------------" << endl;
        cout << "          W E L C O M E           " << endl;
        cout << "----------------------------------" << endl;
        while(true) {
                cout <<"Enter six digits between 1 and 50: " << endl;
                for(int i = 0; i < 6; i++)
                {
                        cin >> user[i];
                }


                for(int i = 0; i < 6; i++) {
                        do {
                                unique = true;

                                lotto[i] = rand() % 49 + 1;

                                for(int j = 0; j < i; j++) {
                                        if(lotto[i] == lotto[j]) {
                                                unique = false;


                                                break;
                                        }
                                }
                        } while(!unique);
                }

                // Bubble sort algorithm
                for(int i = 4; i >= 0; i--)
                {
                        for(int j = 0; j <= i; j++)
                        {
                                if(lotto[j] > lotto[j+1])
                                {
                                        int temp = lotto[j];
                                        lotto[j] = lotto[j+1];
                                        lotto[j+1] = temp;
                                }
                        }
                }

                cout<<endl<<"Lottery array: ";

                for(int i = 0; i < 6; i++)
                {
                        cout << lotto[i] << " | ";
                }

                cout<<endl<<"User array: ";

                for(int i = 0; i < 6; i++)
                {
                        cout << user[i] << " | ";
                }

                //Check for matches between the user array and the lottery array
                int counter = 0;

                for(int i = 0; i < 6; i++)
                {
                        for(int j = 0; j < 6; j++)
                        {
                                if(i != j && lotto[i] == user[j])
                                {
                                        counter++;

                                }
                        }
                }

                if(counter == 6)
                {
                        Counters[1][0]++;
                        cout << endl << "--------------------";
                        cout << endl << "You found "<< counter <<" correct numbers."<< endl;
                        cout << "You are the Grand Prize Winner!"<<endl;
                        cout << "--------------------" << endl;
                }
                else if(counter == 5)
                {
                        Counters[1][1]++;
                        cout << endl << "--------------------";
                        cout << endl << "You found "<< counter <<" correct numbers."<< endl;
                        cout << "You won a big prize"<< endl;
                        cout << "--------------------" << endl;
                }
                else if(counter == 4)
                {
                        Counters[1][2]++;
                        cout << endl << "--------------------";
                        cout << endl <<"You found "<< counter <<" correct numbers."<< endl;
                        cout << "You won, Congratulations!" << endl;
                        cout << "--------------------" << endl;
                }
                else if(counter == 3)
                {
                        Counters[1][3]++;
                        cout << endl << "--------------------";
                        cout << endl << "You found "<< counter <<" correct numbers."<< endl;
                        cout << "You Won!"<<endl;
                        cout << "--------------------" << endl;
                }
                else
                {
                        cout << endl << "--------------------";
                        cout << endl << "You found "<< counter <<" correct numbers."<< endl;
                        cout << "Better luck next time." << endl;
                        cout << "--------------------" << endl;
                }
                counter = 0; // The counter goes back to ZERO.
        }
        return 0;
}
