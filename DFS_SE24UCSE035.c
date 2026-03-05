#include <stdio.h>
#define MAX 100

typedef struct{
    int m_left;
    int c_left;
    int boat;
}State;

State stack[MAX];
int top=-1;
int visited[4][4][2];

int isValid(int m_left,int c_left){
    int m_right=3-m_left;
    int c_right=3-c_left;
    if(m_left<0||c_left<0||m_left>3||c_left>3) return 0;
    if(m_left>0 && m_left<c_left) return 0;
    if(m_right>0 && m_right<c_right) return 0;
    return 1;
}

void printState(State s){
    printf("(M=%d C=%d Boat=%s)\n",s.m_left,s.c_left,s.boat==0?"Left":"Right");
}

void dfs(){
    State start={3,3,0};
    stack[++top]=start;

    while(top>=0){
        State cur=stack[top--];
        printState(cur);

        if(cur.m_left==0 && cur.c_left==0){
            printf("Goal reached\n");
            return;
        }

        int moves[5][2]={{1,0},{2,0},{0,1},{0,2},{1,1}};

        for(int i=0;i<5;i++){
            int m=moves[i][0];
            int c=moves[i][1];
            State next;

            if(cur.boat==0){
                next.m_left=cur.m_left-m;
                next.c_left=cur.c_left-c;
                next.boat=1;
            }else{
                next.m_left=cur.m_left+m;
                next.c_left=cur.c_left+c;
                next.boat=0;
            }

            if(isValid(next.m_left,next.c_left) && !visited[next.m_left][next.c_left][next.boat]){
                visited[next.m_left][next.c_left][next.boat]=1;
                stack[++top]=next;
            }
        }
    }
}

int main(){
    dfs();
    return 0;
}
