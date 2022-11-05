//Brute Force TC - O(N! * N) +O(N! Log N!)
 
class Solution {
  public:
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};


// Optimal Soln TC - O(N) * O(N) = O(N^2)

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for(int i=1; i<n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k-1;

        while(true){
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0)
                break;
            
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
