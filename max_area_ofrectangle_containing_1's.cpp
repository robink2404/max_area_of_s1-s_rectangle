class Solution {
public:


 int solve(vector<int> a)
  {
       int n=a.size();
      vector<int> ans;
         vector<int> ans1;
        stack<int> st;
         stack<int> st1;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(i);
            }
            else
            {
                if(a[st.top()]<a[i])
                {
                    ans.push_back(st.top());
                    st.push(i);
                }
                else
                {
                    while(!st.empty()&&a[i]<=a[st.top()])
                    {
                        st.pop();
                    }
                    if(st.empty())
                    {
                        ans.push_back(-1);
                        st.push(i);
                    }
                    else
                    {
                        ans.push_back(st.top());
                        st.push(i);
                    }
                }
            }
        }  
          for(int i=n-1;i>=0;i--)
        {
            if(st1.empty())
            {
                ans1.push_back(n);
                st1.push(i);
            }
            else
            {
                if(a[st1.top()]<a[i])
                {
                    ans1.push_back(st1.top());
                    st1.push(i);
                }
                else
                {
                    while(!st1.empty()&&a[i]<=a[st1.top()])
                    {
                        st1.pop();
                    }
                    if(st1.empty())
                    {
                        ans1.push_back(n);
                        st1.push(i);
                    }
                    else
                    {
                        ans1.push_back(st1.top());
                        st1.push(i);
                    }
                }
            }
        }
        
       reverse(ans1.begin(),ans1.end());
             int maxarea=0,currarea=0;
              for(int i=0;i<n;i++)
              {
                  currarea=a[i]*(ans1[i]-ans[i]-1);
                  if(maxarea<currarea)
                  maxarea=currarea;
              }
        return maxarea;
  }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                v[j]+=1;
                else
                v[j]=0;
            }
            ans=max(ans,solve(v));
        }

return ans;
        
        
    }
};