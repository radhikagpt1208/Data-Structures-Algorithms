/*
-> Problem Statement :
SuperComputer Inc. have built a super-fast computer server consisting of N hyper-scalar lightning-fast processors Beta 007.
These processors are numbered from 1 to N and are used to process independent jobs. Every new incoming job is assigned to an
arbitrary processor. Sometimes, a processor may be assigned too many jobs while other processors have a relatively light load
(or even wait idly). In that case, the whole system undergoes rebalancing.
Rebalancing proceeds in rounds. In each round, every processor can transfer at most one job to each of its neighbors on the bus.
Neighbors of the processor i are the processors i-1 and i+1(processors 1 and N have only one neighbor each, 2 and N-1 respectively)
The goal of rebalancing is to achieve that all processors have the same number of jobs.
Given the number of jobs initially assigned to each processor, you are asked to determine the minimal number of rounds needed
to achieve the state when every processor has the same number of jobs, or to determine that such rebalancing is not possible.
-> Input specification :
The input file consists of several blocks. Each block begins with a line containing a single number N(1<= N <=9000) - the number of
processors. N numbers follow, separated by spaces and/or end of line characters. The i-th number denotes the number of jobs
assigned to the i-th processor before rebalancing. There is a blank line after each block. The last block is followed by a single
number -1 on a separate line (which should not be processed).
->Output file specification :
For each block in the input file, output the minimal number of rounds needed to rebalance loads for all the processors.
If it is not possible to rebalance jobs so that each processor has the same number of jobs, output -1.

Greedy Approach:
1.First find the final load that each processor will have. We can find it by sum(arr[1], arr[2],...,arr[n])/n,let us call it load.
2.If load is not an integer,simply return -1.
3.Else,in the final state, each of the processor will have final load = load.
4.For each index i from 1 to n-1, create a partition of (1...i) and (i+1...n) and find the max amount of load that is to be shared
  b/w these two partitions.The answer will be maximum of all the loads shared b/w all the partitions with i varying from 1 to n-1.
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    while(1){
        //take input no of processors
        int max_load = 0, load = 0;
        cin>>n;
        int arr[n];

        //stop taking input if N = -1
        if(n == -1)
            break;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
            load += arr[i];
        }

        //find the load that is to be divided equally (calculate above)
        //if load is not an integer, it is impossible to divide the load equally
        if(load % n != 0){
            cout<<-1<<endl;
            continue;
        }
        load = load/n;

        int diff = 0;
        //greedy step
        for(int i = 0; i < n; i++){
            //find difference b/w final load to be assigned and current load
            //Keep adding this difference in 'diff' variable
            diff += arr[i] - load;
            //If the net difference is negative i.e.we need diff amount till i-th index
            if(diff < 0)
                max_load = max(max_load, -1 * diff);
            //If diff is positive i.e. we have to give diff amout to (n-i) processors
            else
                max_load = max(max_load, diff);
        }
        cout<<max_load<<endl;
    }
    return 0;
}



























