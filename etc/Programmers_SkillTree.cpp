#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int skill_check(char s, const char* tmp);
int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
	int check, idx;
	int skill_size = 0;
	int answer = 0;
	int j = 0;
	for (int i = 0; skill[i] != 0; i++) skill_size++;
	for (int i = 0; i < skill_trees_len; i++) {
		check = idx = 0;
		for (j = 0; skill_trees[i][j] != 0; j++) {
			if ((idx = skill_check(skill_trees[i][j], skill)) != -1) {
				if (check != idx)
					break;
				check++;
				if (check == skill_size)
					break;
			}
		}
		if (check == skill_size || skill_trees[i][j] == 0)
			answer++;
	}
	return answer;
}
int skill_check(char s, char* tmp) {
	for (int i = 0; tmp[i] != 0; i++) {
		if (tmp[i] == s)
			return i;
	}
	return -1;
}
