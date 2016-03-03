#include <stdio.h>

#include <vector>

using namespace std;

typedef unsigned short int state;

typedef struct pair_
{int a,b; } pair;

int solved(vector<state> &states) {
    for(int i=0; i<states.size(); ++i)
        if(states[i] == 0xFF) return 1;
    return 0;
}

/* these are all 1-based !!! bit_1 is lsb! */
#define GET_BIT(val,k) ((val) & (1<<((k)-1)))
#define BITS_DIFFER(val,i,j) (GET_BIT(val,i) != GET_BIT(val,j))
#define FLIP(val,i,j) (val ^ (1<<((i)-1)) ^ (1<<((j)-1)))
#define ARR_LEN(X) (sizeof((X))/sizeof(*(X)))

void
transition(vector<state> &before, vector<state> &after)
{
    // initializer list
    // without duplicate removal, 64 (2^6)
    // worst case: 3 transitions make 64*64*64 = 2^18 = 256k bytes = 1MB when sizeof(int)==4
    int adj[] = {
        1,2 , 1,3 , 1,5 , 1,9,
        /*2,1*/2,4 , 2,6 , 2,10,
        /*3,1*/3,4 , 3,7 , 3,11,
        /*4,3 , 4,2*/4,8 , 4,12,
        /*5,1*/5,6 , 5,7 , 5,13,
        /*6,5 , 6,2*/6,8 , 6,14,
        /*7,5 , 7,3*/7,8 , 7,15,
        /*8,7 , 8,6 , 8,4*/8,16,

        9,10 , 9,11 , 9,13 , 9,1,
        /*10,9*/10,12 , 10,14 , 10,2,
        /*11,9*/11,12 , 11,15 , 11,3,
        /*12,11 , 12,10*/12,16 , 12,4,
        /*13,9*/13,14 , 13,15 , 13,5,
        /*14,13 , 14,10*/14,16 , 14,6,
        /*15,13 , 15,11*/15,16 , 15,7,
        /*16,15 , 16,14 , 16,12*/16,8
    };

//    printf("before has: \n");
//    for(int z=0; z<before.size(); ++z) {
//        printf("%04X ", before[z]);
//    }
//    printf("\n");

    // for each input state
    for(int i=0; i<before.size(); ++i) {
        state in_state = before[i];
    
        // for each vertex
        for(int j=0; j<ARR_LEN(adj)/2; j+=2) {
            int v0=adj[j];
            int v1=adj[j+1];
            // opposite lights?
            if(BITS_DIFFER(in_state, v0, v1)) {
                // then make it to the new state
                //printf("%04X -> %04X\n", in_state, FLIP(in_state, v0, v1));
                after.push_back(FLIP(in_state, v0, v1));                
            }
        }
    }

    //printf("--\n");
}

int main(int ac, char **av)
{
    int case_i;
    int num_cases;
    scanf("%d", &num_cases);

    // loop over each test case
    for(case_i=0; case_i<num_cases; ++case_i) {
        //
        int answer = 0;
        vector<state> states0, states1, states2, states3;

        printf("Case #%d: ", case_i+1);

        // get input
        state st = 0;
        for(int i=0; i<16; ++i) {
            int t=0;
            scanf("%d ", &t);
            st = (st << 1) | t;
        }
        states0.push_back(st);

        // is the state already ok?
        if(solved(states0)) goto done;
        answer += 1;
        // transition state 0 -> 1
        transition(states0, states1);
        if(solved(states1)) goto done;
        answer += 1;
        // transition state 1 -> 2
        transition(states1, states2);
        if(solved(states2)) goto done;
        answer += 1;
        // transition state 2 -> 3
        transition(states2, states3);
        if(solved(states3)) goto done;
        answer += 1;
    
        done:
        if(answer > 3) printf("more\n");
        else printf("%d\n", answer);
    }

    return 0;
}
