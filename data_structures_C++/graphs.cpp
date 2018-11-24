#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph {
    private:
        int a[30][30];
        int vertices;
    public:
        Graph(int num) {
            for(int i = 0; i < num; i++) {
                for(int j = 0; j < num; j++) {
                    a[i][j] = 0;
                }
            }
            vertices = num;
        }
        void insertEdge(char x, char y) {
            int start = int(x) - 65;
            int end = int(y) - 65;
            a[start][end] += 1;
            a[end][start] += 1;
        }
        void displayConnections() {
            for(int i = 0; i < vertices; i++) {
                cout << char(i + 65) << " -> ";
                for(int j = 0; j < vertices; j++) {
                    if(a[i][j] == 1) cout << char(j + 65) << " ";
                }
                cout << "\n";
            }
        }
        void printMatrix() {
            cout << "  A B C D E F G H I J\n";
            for(int i = 0; i < vertices; i++) {
                cout << char(i + 65) << " ";
                for(int j = 0; j < vertices; j++) {
                   cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
        void DFS() {
            stack<char> S;
            char dfs_arr[vertices];
            int dfs_i = 0;
            int top = 0;

            int status[vertices];   // status- 1=not_visited 2=on_stack 3=visited
            for(int j = 0; j < vertices; j++) status[j] = 1;

            dfs_arr[dfs_i++] = 'A';
            status[0] = 3;
            S.push(char(top + 65));
            while(S.size() != 0) {
                for(int j = vertices - 1; j >= 0; j--) {
                    if(a[top][j] == 1 && status[j] == 1) {
                        S.push(char(j + 65));
                        status[j] = 2;
                    }
                }
                top = int(S.top()) - 65;
                S.pop();
                if(S.size() != 0) dfs_arr[dfs_i++] = char(top + 65);
                status[top] = 3;
                
                // checking if any node is left unvisited (in case of NOT connected graph)
                if(S.size() == 0) {
                    for(int j = 0; j < vertices; j++) {
                        if(status[j] == 1) {
                            S.push(char(j + 65));
                            dfs_arr[dfs_i++] = char(j + 65);
                            status[j] = 3;
                            top = j;
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < vertices; j++) {
                cout << dfs_arr[j] << " ";
            }
            cout << '\n';
        }
        void BFS() {
            queue<char> Q;
            char bfs_arr[vertices];
            int bfs_i = 0;
            int front = 0;

            int status[vertices];   // status- 1=not_visited 2=on_queue 3=visited
            for(int j = 0; j < vertices; j++) status[j] = 1;

            Q.push(char(front + 65));
            while(Q.size() != 0) {
                front = int(Q.front()) - 65;
                Q.pop();
                bfs_arr[bfs_i++] = char(front + 65);
                status[front] = 3;

                for(int j = 0; j < vertices; j++) {
                    if(a[front][j] == 1 && status[j] == 1) {
                        Q.push(char(j + 65));
                        status[j] = 2;
                    }
                }

                // checking if any node is left unvisited (in case of NOT connected graph)
                if(Q.size() == 0) {
                    for(int j = 0; j < vertices; j++) {
                        if(status[j] == 1) {
                            Q.push(char(j + 65));
                            front = j;
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < vertices; j++) {
                cout << bfs_arr[j] << " ";
            }
            cout << '\n';
        }
};

class LkListGraph {
    private:
        struct node {
            char vertex;
            struct node* next;
        };
        struct node a[30];
        int vertices;

        void insert(char x, char ver) {
            int start = int(x) - 65;
            struct node* ptr = new struct node;
            ptr -> vertex = ver;
            ptr -> next = NULL;

            struct node* travy = &a[start];
            while(travy -> next != NULL) {
                travy = travy -> next;
            }
            travy -> next = ptr;
        }
    public:
        LkListGraph(int num) {
            for(int i = 0; i < num; i++) {
                a[i].vertex = char(i + 65);
                a[i].next = NULL;
            }
            vertices = num;
        }
        void insertEdge(char x, char y) {
            insert(x, y);
            insert(y, x);
        }
        void displayConnections() {
            struct node* ptr;
            for(int i = 0; i < vertices; i++) {
                cout << char(i + 65) << " -> ";
                ptr = a[i].next;
                while(ptr != NULL) {
                    cout << ptr -> vertex << " ";
                    ptr = ptr -> next;
                }
                cout << "\n";
            }
        }
        void DFS() {
            stack<char> S;
            char dfs_arr[vertices];
            int dfs_i = 0;
            int top = 0;

            int status[vertices];   // status- 1=not_visited 2=on_stack 3=visited
            for(int j = 0; j < vertices; j++) status[j] = 1;

            dfs_arr[dfs_i++] = 'A';
            status[0] = 3;
            S.push(char(top + 65));
            while(S.size() != 0) {
                struct node* ptr = &a[top];
                while(ptr != NULL) {
                    if(ptr -> vertex && status[top] == 1) {
                        S.push(ptr -> vertex);
                        status[int(ptr -> vertex) - 65] = 2;
                    }
                    ptr = ptr -> next;
                }
                top = int(S.top()) - 65;
                S.pop();
                if(S.size() != 0) dfs_arr[dfs_i++] = char(top + 65);
                status[top] = 3;
                
                // checking if any node is left unvisited (in case of NOT connected graph)
                if(S.size() == 0) {
                    struct node* ptr = &a[0];
                    while(ptr != NULL) {
                        int v_num = int(ptr -> vertex) - 65;
                        if(status[v_num] == 1) {
                            S.push(ptr -> vertex);
                            dfs_arr[dfs_i++] = ptr -> vertex;
                            status[v_num] = 3;
                            top = v_num;
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < vertices; j++) {
                cout << dfs_arr[j] << " ";
            }
            cout << '\n';
        }
        void BFS() {
            queue<char> Q;
            char bfs_arr[vertices];
            int bfs_i = 0;
            int front = 0;

            int status[vertices];   // status- 1=not_visited 2=on_queue 3=visited
            for(int j = 0; j < vertices; j++) status[j] = 1;

            Q.push(char(front + 65));
            while(Q.size() != 0) {
                front = int(Q.front()) - 65;
                Q.pop();
                bfs_arr[bfs_i++] = char(front + 65);
                status[front] = 3;

                struct node* ptr = &a[front];
                while(ptr != NULL) {
                    if(ptr -> vertex && status[front] == 1) {
                        Q.push(ptr -> vertex);
                        status[int(ptr -> vertex) - 65] = 2;
                    }
                    ptr = ptr -> next;
                }

                // checking if any node is left unvisited (in case of NOT connected graph)
                if(Q.size() == 0) {
                    struct node* ptr = &a[0];
                    while(ptr != NULL) {
                        int v_num = int(ptr -> vertex) - 65;
                        if(status[v_num] == 1) {
                            Q.push(ptr -> vertex);
                            front = v_num;
                            break;
                        }
                    }
                }
            }
            for(int j = 0; j < vertices; j++) {
                cout << bfs_arr[j] << " ";
            }
            cout << '\n';
        }
};

main() {
    // Graph using matrix
    Graph g(10);
    cout << "Graph using matrix-\n";
    g.insertEdge('A', 'D');
    g.insertEdge('J', 'A');
    g.insertEdge('C', 'D');
    g.insertEdge('E', 'H');
    g.insertEdge('I', 'A');
    g.insertEdge('J', 'F');
    g.displayConnections();
    cout << "\n";
    g.printMatrix();
    cout << "\nDFS -\n";
    g.DFS();
    cout << "\nBFS -\n";
    g.BFS();
    cout << '\n';

    // Graph using linked list
    LkListGraph lg(10);
    cout << "Graph using linked list-\n";
    lg.insertEdge('A', 'D');
    lg.insertEdge('J', 'A');
    lg.insertEdge('C', 'D');
    lg.insertEdge('E', 'H');
    lg.insertEdge('I', 'A');
    lg.insertEdge('J', 'F');
    lg.displayConnections();
    cout << "\nDFS -\n";
    g.DFS();
    cout << "\nBFS -\n";
    g.BFS();
}