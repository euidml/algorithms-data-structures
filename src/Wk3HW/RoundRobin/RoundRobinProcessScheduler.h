#include <iostream>
#include <sstream>
#include <fstream>
#include "CircularList.h"
#include <vector>


using namespace std;

#ifndef ROUNDROBINPROCESSSCEDULER_H
#define ROUNDROBINPROCESSSCEDULER_H

/**
 * @brief 
 * 
 */
class RoundRobinProcessScheduler{
    private:
        /**
         * @brief explain each variables
         * 
         */
        //timeSlice refers tims slice
        int timeSlice;
        // CircularLinkedList object refers process of tasks
        CircularLinkedList processTimes;
        // processDoneId refers list of ids in order ot the time when its task is done. 
        // turnaroundForEach refers turnaroundForEach refers turnaround time when each task is done
        // processDoneId and turnaroundForEach connected with same indexes
        vector<int> processDoneId, turnaroundForEach;
        // turnaround refers turnaround time.
        int turnaround;

    public:
        RoundRobinProcessScheduler(){}
        // RoundRobinProcessScheduler(int time,  vector<int> processList){
        //     timeSlice = time;
        //     for(int i = 0; i < processList.size(); i++){
        //         processTimes.insert(i + 1, processList[i]);
        //     }
        // }
        /**
         * @brief this method is to read data file and convert it into data storing into proper variables
         * 
         * @example
         * RoundRobinProcessScheduler r;
         * r.LoadFromFile("something.txt")
         * 
         * @result
         * N/A
         * 
         * @timecomplexity:  
         * O(n^2 * log(n))
         * @param fileName - refers a name of the file in string
         * @return none
         */
        void LoadFromFile(string fileName){
            // Create a text string, which is used to output the text file
            string myText;
            // Read from the text file
            ifstream MyReadFile(fileName);
            if(getline (MyReadFile, myText))
                timeSlice = stoi(myText);
            if(getline (MyReadFile, myText)){
                //  O(n*log(n)) for stringstream constructor.
                stringstream ss(myText);
                string token;
                int i = 1;
                // O(n) for while loop because getline iss generally linear in the resulting length of str.
                while (getline(ss, token, ',')) {
                    // Convert the token (substring between commas) to an integer and add it to the vector
                    int number;
                    //  O(n*log(n)) for stringstream constructor.
                    stringstream(token) >> number;
                    // O(1) processTimes.insert()
                    processTimes.insert(i, number);
                    i++;
                }
            }
            // Close the file
            MyReadFile.close();
            
        }
        /**
         * @brief this method is to proceed the process of task in Round Robin.
         * 
         * @example
         *  RoundRobinProcessScheduler r;
         * ....
         * r.Process();
         * 
         * 
         * @result
         * N/A
         * 
         * @timecomplexity: O(n^2)
         * 
         * @param none
         * @return nono
         */
        void Process(){
            // if there's no task in the process, then cannot process it.
            if(!processTimes.getLastNode())
                return;
            //setting the node to be the first added node
            processTimes.goToNext();
            // set turn around 0.
            turnaround = 0;
            Node* temp;
            // runs until there's no task left in the process.
            // O(n)
            while(processTimes.getLastNode()){
                // getLastNode - O(1)
                temp = processTimes.getLastNode();
                if(temp -> data <= timeSlice){
                    turnaround += (temp -> data);
                    // push_back() - O(1)
                    processDoneId.push_back(temp -> id);
                    turnaroundForEach.push_back(turnaround);
                    temp -> data = 0;
                    // deleteNode() - O(n)
                    processTimes.deleteNode(0);
                }else{
                    turnaround += timeSlice;
                    temp -> data -= timeSlice;
                }
                // goToNext O(1)
                processTimes.goToNext();
            }
        }
        /**
         * @brief this method is to show the results of process in round robin
         * 
         * @example
         * // Aussuming data.txt is:
         * // 5
         * // 10,30,15
         * RoundRobinProcessScheduler r;
         * r.LoadFromFile("data.txt");
         * r.Process();
         * r.ShowResults();
         * 
         * @result
         * Process 1 is done with turnaround: 20
         * Process 3 is done with turnaround: 40
         * Process 2 is done with turnaround: 55
         * Average turnaround time: 38.3333
         * 
         * @timecomplexity:  O(n)
         * 
         * @param none
         * @return none
         */
        void ShowResults (){
            // if Process() not executed first,
            if(processDoneId.size() == 0)
                return;
            // total; sum of all turnaround times
            double total = 0;
            // O(n)
            // prints each task id and turn around time of each tasks
            for(int i = 0; i < turnaroundForEach.size(); i++){
                total += turnaroundForEach[i];
                cout << "Process " << processDoneId[i] << " is done with turnaround: " << turnaroundForEach[i] << endl;
            }
            cout << "Average turnaround time: " << (total/(double)turnaroundForEach.size()) << endl;
        }

        

};

#endif