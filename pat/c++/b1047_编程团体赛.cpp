#include<stdio.h>
#include<map>

using namespace std;

int main(){
	int team_score[1010];
	memset(team_score, 0, sizeof(team_score));
	int N, team, mn, score;
	scanf("%d", &N);

	for(int j = 0; j < N; j++){
		scanf("%d-%d %d", &team, &mn, &score);
		team_score[team] = team_score[team] + score;
	}

	int max = 0, max_index;
	for(int i = 0; i < 1010; i++){
		if(team_score[i] > max){
			max = team_score[i];
			max_index = i;
		}
	}
	printf("%d %d", max_index, team_score[max_index]);

	return 0;
}

