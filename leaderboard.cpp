#include <fstream> 
#include "global.h"

struct Score {
    double time;
    int death;
    int money;
    int point;
};

vector<int> sc(50);

void save_scores() {
    FILE *fp = fopen("./save/score_save.txt", "a");
    //fprintf(fp, "%lf ", timing/45);
    //fprintf(fp, "%d ", thief.death_count);
    //fprintf(fp, "%d ", coin.moneycount * 20);
    int point = coin.moneycount * 50 - (timing/45)/10;
    cout << "In this round, \n";
    cout << "You got " << coin.moneycount << " coins\n";
    //cout << "You died " << thief.death_count << " times\n";
    cout << "Score saved, you get " << point << " points" << endl;
    fprintf(fp, "%d\n", point);
    fclose(fp);
}
void load_scores() {
    ifstream fin("./save/score_save.txt");
    int score;
    int i = 0;
    while(fin >> score)  sc[i++] = score;
    sort(sc.begin(), sc.end(), greater<int>());
    //for(auto &i : scores)  cout << i << endl;
    fin.close();
}
void show_leaderboard() {
    load_scores();
    cout << "--- LEADERBOARD --- \n";
    for(int i = 0 ; i < 10 ; i++) {
        cout << "[ No." << i+1 << " ]" << sc[i] << "pts\n";
    }
}