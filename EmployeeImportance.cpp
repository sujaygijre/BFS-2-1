/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> idsMap;
        unordered_map<int, Employee*> usEmp;
        vector<int> inorder;
        for (int i=0;i<employees.size();i++) {
            idsMap[employees[i]->id] = employees[i]->subordinates;
            usEmp[employees[i]->id] = employees[i];
        }

        queue<int> q;
        q.push(id);
        int answer = usEmp[id]->importance;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            vector<int> direct = idsMap[node];
            for (int i=0;i<direct.size();i++) {
                answer += usEmp[direct[i]]->importance;
                q.push(direct[i]);
            }
        }

        return answer;
    }
};
