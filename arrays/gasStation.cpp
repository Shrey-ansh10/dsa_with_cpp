// LC 134 : Gas Station

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.


#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;
        int n = gas.size();

        // to check for potential ans
        int currGas=0;
        int ans = 0;

        for(int i=0; i<n; i++){ // O(n)
            totalGas += gas[i];
            totalCost += cost[i];

            currGas += gas[i] - cost[i]; // add gas at this station and remove the cost to get to next station
            
            if(currGas < 0){ // at any point if we have -ve gas we can't travel
                ans=i+1; //change the start index to next idx
                currGas=0; // reset gas to 0
            }
        }

        if(totalCost > totalGas){ // if we dont have enought gas, we can't complete the circuit
            return -1;
        }else{
            return ans;
        }

    }

    