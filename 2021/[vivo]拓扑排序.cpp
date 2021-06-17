/*
一个完整的软件项目往往会包含很多由代码和文档组成的源文件。编译器在编译整个项目的时候，可能需要按照依赖关系来依次编译每个源文件。
比如，A.cpp 依赖 B.cpp，那么在编译的时候，编译器需要先编译 B.cpp，才能再编译 A.cpp。 假设现有 0，1，2，3 四个文件，0号文件依赖1号文件，
1号文件依赖2号文件，3号文件依赖1号文件，则源文件的编译顺序为 2,1,0,3 或 2,1,3,0。现给出文件依赖关系，如 1,2,-1,1，表示0号文件依赖1号文件，
1号文件依赖2号文件，2号文件没有依赖，3号文件依赖1号文件。请补充完整程序，返回正确的编译顺序。注意如有同时可以编译多个文件的情况，
按数字升序返回一种情况即可，比如前述案例输出为：2,1,0,3
输入例子1:
"1,2,-1,1"

输出例子1:
"2,1,0,3"
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 编译顺序
     * @param input string字符串
     * @return string字符串
     */
    vector<int> num;
     
    string compileSeq(string input) {
        // write code here
        const char *str = input.c_str();
        char *p = strtok((char *)str, ",");
        while(p)
        {
            num.push_back(atoi(p));
            p = strtok(NULL, ",");
        }
        int n = num.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> G(n);
        for(int i = 0; i <n; i++)
        {
            if(num[i] > -1)
            {    indegree[i]++;
                G[num[i]].push_back(i);
            }
        }
         
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i = 0; i <n; i++)
        {
            if(indegree[i] == 0)
                que.push(i);
        }
        string res;
        while(!que.empty())
        {
            int node = que.top();
            que.pop();
            if(res.empty())
                res = to_string(node);
            else
                res = res + "," + to_string(node);
             
            for(auto it : G[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    que.push(it);
            }
        }
        return res;
    }
};
