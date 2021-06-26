#pragma once

#include "stdafx.h"

// 프로그래머스 - Lv 2

// 스택 / 큐 ( stack / queue )
// 다리를 지나는 트럭

//======================================================================================
//======================================================================================
int Cross_the_bridge_03(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    if (bridge_length < 1 && bridge_length > 10000)
        return answer;
    if (weight < 1 && weight > 10000)
        return answer;

    queue<int> onthebridge;
    onthebridge.push(truck_weights[0]);
    answer = 1;

    int passTrucks = truck_weights.size();
    int cur_weight = truck_weights[0];
    int start = 1;

    while (passTrucks > 0)
    {
        ++answer;

        if (onthebridge.size() == bridge_length)
        {
            if (onthebridge.front() > 0)
                --passTrucks;

            cur_weight -= onthebridge.front();
            onthebridge.pop();
        }

         if (start < truck_weights.size() && (weight - cur_weight) >= truck_weights[start])
         {
             cur_weight += truck_weights[start];
             onthebridge.push(truck_weights[start++]);
         }
         else
             onthebridge.push(0);
    }

    return answer;
}
//======================================================================================
//======================================================================================


//======================================================================================
//======================================================================================
int Cross_the_bridge(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	queue<int> que_bridge;
	int Cur_Weight = 0;
	int Cur_Num = 0;
	int TruckCount = truck_weights.size();

	do
	{
		++answer;

		if (que_bridge.size() >= bridge_length)
		{
			if (que_bridge.front() > 0)
				--TruckCount;

			Cur_Weight -= que_bridge.front();
			que_bridge.pop();
		}

		if (truck_weights.size() > Cur_Num && weight >= (Cur_Weight + truck_weights[Cur_Num]))
		{
			que_bridge.push(truck_weights[Cur_Num]);
			Cur_Weight += truck_weights[Cur_Num++];
		}
		else
			que_bridge.push(0);

	} while (TruckCount > 0);

	return answer;
}
//======================================================================================
//======================================================================================

//======================================================================================
//======================================================================================
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> queueBridge;

    int _iarriveTruck = 0;
    int _icurrWeight = 0;
    int _icurrTruck = 0;

    do
    {
        ++answer;

        if (queueBridge.size() >= bridge_length)
        {
            if (queueBridge.front() > 0)
                ++_iarriveTruck;

            _icurrWeight -= queueBridge.front();
            queueBridge.pop();
        }


        if (_icurrWeight + truck_weights[_icurrTruck] <= weight
            && _icurrTruck < truck_weights.size())
        {
            _icurrWeight += truck_weights[_icurrTruck];
            queueBridge.push(truck_weights[_icurrTruck++]);
        }
        else
            queueBridge.push(0);
    } while (_iarriveTruck < truck_weights.size());

    return answer;
}
//======================================================================================
//======================================================================================