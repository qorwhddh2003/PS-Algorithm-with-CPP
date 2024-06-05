#include <string>
#include <vector>

using namespace std;

void _rotate(vector<vector<int>> &key){
    int M = key.size();
    vector<vector<int>> temp(M, vector<int>(M, 0));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            temp[i][j] = key[M - j - 1][i];
        }
    }
    key = temp;
    return;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size(), cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(lock[i][j] == 0) cnt++;
        }
    }
    
    for(int t = 0; t < 4; t++){
        for(int i = -19; i <= 19; i++){
            for(int j = -19; j <= 19; j++){
                int flag = 0, count = 0;
                for(int y = 0; y < M; y++){
                    for(int x = 0; x < M; x++){
                        int ny = y + i;
                        int nx = x + j;
                        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                        if(lock[ny][nx] == 1 && key[y][x] == 1) flag = 1;
                        else if(lock[ny][nx] == 0 && key[y][x] == 1) count++;                    
                    }
                }
                if(!flag && cnt == count) return true;
            }
        }
        
        _rotate(key);
    }
    
    return false;
}