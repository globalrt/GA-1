//
//  main.cpp
//  0-1Knapsack
//
//  Created by JIBA on 2016. 3. 26..
//  Copyright © 2016년 JIBA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>



using namespace std;

const int gen_limit = 100;  //
const int l = 500;          //length of chromosome
const int n = 100;          //size of population
const double pc = 0.9;      //probability of crossover
const double pm = 0.01;     //probability of mutation
const int capacity_limit=13743;

int weight_array[l];
int profit_array[l];

void set_spec(){
    ifstream fin;
    fin.open("/Users/JIBA/Documents/0-1Knapsack/0-1Knapsack/TestData(0-1Knapsack).txt");
    
    string line;
    if (fin.is_open()) {
        for (int i=0; i<5; i++) {
            getline(fin,line);
        }
        int i=0;
        while (fin>>i>>weight_array[i-1]>>profit_array[i-1]) {
        }
    }
}


class individual{
    
public:
    bool chrom[l];
    double fitness=0;
    
    int capacity=0;
    int profit=0;
    
    void ini_chrom(){
        for (int i=0; i<l; i++) {
            chrom[i]=rand()%2;
        }
    }
    
    void update(){
        capacity = 0;
        profit = 0;
        
        for (int i=0; i<l; i++) {
            capacity += (weight_array[i]*chrom[i]);
            profit += (profit_array[i]*chrom[i]);
        }
        
        if (capacity > capacity_limit) {
            fitness = 0;
        }
        else{
            fitness = (double)profit;
        }
    }
    
    void indi_mutation(){
        
        for (int i=0; i<l; i++) {
            int p = rand()%100;
            int pm_100 = pm*100;
            
            if (pm_100>p) {
                if (chrom[i]==false)
                    chrom[i]=true;
                else
                    chrom[i]=false;
            }
        }
    }
};

class population{
  
public:
    int gen_num;
    double aver_fitness;
    double best_fitness;
    
    individual* pop[n];
    
    void ini_generate(){
        gen_num=1;
        for (int i=0; i<n; i++) {
            pop[i]=new individual;
            pop[i]->ini_chrom();
            pop[i]->update();
        }
    }
    
    void cal_aver_best(){
        best_fitness=0;
        int temp=0;
        
        for (int i=0; i<n; i++) {
            best_fitness = max(best_fitness,pop[i]->fitness);
            temp += pop[i]->fitness;
        }
        aver_fitness = (double)temp/n;
    }
    
    void mutation(){
        for (int i=0; i<n; i++) {
            pop[i]->indi_mutation();
        }
    }
    
    void cal_fitness(){
        for (int i=0; i<n; i++) {
            pop[i]->update();
        }
    }
    
    void point_3_cross(){
        int point_1;
        int point_2;
        int point_3;
        
        point_1 = rand()%
        
    }
}


int main(int argc, const char * argv[]) {
    set_spec();
    
    srand((unsigned)time(NULL));
    
    population test;
    
    test.ini_generate();
    
    test.cal_aver_best();
    
//    cout<<test.aver_fitness<<"\t\t"<<test.best_fitness<<endl;
    
    
    cout<<test.pop[0]->fitness<<"\t\t"<<test.pop[0]->profit<<endl;
    cout<<test.pop[1]->fitness<<"\t\t"<<test.pop[1]->profit<<endl;
    
    swap_ranges(&(test.pop[0]->chrom[0]), &(test.pop[0]->chrom[500]), &(test.pop[1]->chrom[0]));
    
    test.cal_fitness();
    test.cal_aver_best();

    cout<<test.pop[0]->fitness<<"\t\t"<<test.pop[0]->profit<<endl;
    cout<<test.pop[1]->fitness<<"\t\t"<<test.pop[1]->profit<<endl;
    
    
    test.mutation();
    test.cal_fitness();
    test.cal_aver_best();
    cout<<test.aver_fitness<<"\t\t"<<test.best_fitness<<endl;
    
    
    return 0;
}
