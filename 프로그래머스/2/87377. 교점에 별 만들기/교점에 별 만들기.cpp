#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 9223372036854775807
typedef long long ll;

set<pair<ll, ll>> intersection;

void intersect(int idx, vector<vector<int>> &line) {
    for(int i = idx + 1; i < line.size(); i++) {
        ll denominator = (ll)line[idx][0] * line[i][1] - (ll)line[idx][1] * line[i][0];
        
        if(denominator != 0) {
            double x = ((double)line[idx][1] * line[i][2] - (double)line[idx][2] * line[i][1]) / denominator;
            double y = ((double)line[idx][2] * line[i][0] - (double)line[idx][0] * line[i][2]) / denominator;

            if(x - (ll)x == 0 && y - (ll)y == 0)
                intersection.insert({x, y});
        }
    }
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    for(int i = 0; i < line.size() - 1; i++) {
        intersect(i, line);
    }
    
    ll minX = MAX;
    ll maxX = -MAX;
    ll minY = MAX;
    ll maxY = -MAX;

    for(auto& i : intersection) {
        minX = min(minX, i.first);
        maxX = max(maxX, i.first);
        minY = min(minY, i.second);
        maxY = max(maxY, i.second);
    }

    for(ll y = minY; y <= maxY; y++) {
        string tmp = "";
        
        for(ll x = minX; x <= maxX; x++) {
            tmp += ".";
        }
        
        answer.push_back(tmp);
    }

    for(auto& i: intersection) {
        answer[maxY - i.second][i.first - minX] = '*';
    }
    
    return answer;
}