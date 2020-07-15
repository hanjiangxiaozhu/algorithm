#include "solution.h"

solution::solution()
{

}

int solution::lengthOfLongestSubstring(string s) {
    int ans = 0;
    if(s.empty()) return ans;

    int start(0),end(0);
    while(end<s.size())
    {
        char temp = s[end];
        for(size_t index=start;index<end;index++){
            if(s[index] == temp) start = index;
            ans = max(ans,end-start);
        }
        end++;
    }
    return ans;
}

string solution::intToRoman(int num)//12
{
    static map<int,string> table={
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"VI"},
        {1,"I"}
    };
    string ans;
    if(num > 3999 || num < 1) return ans;

    for(map<int,string>::iterator it = table.begin();it!=table.end();it++){
        int i = it->first;
        while(num - i > 0){
            num = num -i;
            ans.append(it->second);
        }
    }
    return ans;
}

float solution::getCalTimeOfFunc(){
    struct timeval tpstart,tpend;

    float timeuse1;
    gettimeofday(&tpstart,NULL);
    //function();
    gettimeofday(&tpend,NULL);
    timeuse1=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;//us
}

void solution::nextPermutation(vector<int> &nums){
    //4,2, 0,2,3,2,0
    if (nums.size()<2) return;

    vector<int>::iterator j;

    for(vector<int>::iterator i=nums.end()-1;i!=nums.begin();--i){
        j=i-1;
        if(*j<*i){
            for(vector<int>::iterator k=nums.end()-1;k!=j;--k){
                if(*k>*j){
                    int tmp=*k;
                    *k=*j;
                    *j=tmp;
                    sort(j+1,nums.end());
                    return;
                }
            }
        }
    }
    if(j==nums.begin())
    {
        sort(nums.begin(),nums.end());
        return;
    }
}


int erfen(vector<int>& nums, int target, int left, int right){
    int mid = left + (right - left) / 2;
    if(mid == left) return mid;

    if(nums[mid] == target) 
    {
        return mid;
    }else if(target < nums[mid]){
        return erfen(nums, target, left, mid - 1);
    }else{
        return erfen(nums, target, left + 1, mid);
    }
}

vector<int> solution::searchRange(vector<int>& nums, int target) {
    int temp = -1;
    if(nums.size() == 1 && nums[0] == target) temp = 0; 
    if(nums.size() < 2) return {temp,temp};

    int left = 0, right = nums.size() - 1, mid = 0;
    int start = 0, end = 0;
    while(left < right){
        mid = (right + left) / 2;
        if(nums[mid] >= target){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if(nums[left] == target) start = left;
    else return {-1,-1};

    left = 0;
    right = nums.size() - 1;
    while(left < right){
        int mid = (right + left + 1) / 2;
        if(nums[mid] <= target){
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    if(nums[right-1] == target) end = right;
    else return {-1,-1};

    return {start, end};
}


bool judgeVec9(vector<char>& Vec9){
    map<char,bool> ref={{'1',false},{'2',false},{'3',false},{'4',false},{'5',false},{'6',false},{'7',false},{'8',false},{'9',false}};
    for(int i=0;i<9;i++)
    {
        if(Vec9[i]=='.') continue;
        else{
            map<char,bool>::iterator f=ref.find(Vec9[i]);
            if (f!=ref.end()&&f->second) return true;
            f->second=true;
        }
    }
    return false;
}

bool solution::isValidSudoku(vector<vector<char>>& board) {

    vector<char> vec2Judge;
    for(int i=0;i<9;i++){
        if (judgeVec9(board[i])) return false;
        for(int j=0;j<9;j++){
            vec2Judge.push_back(board[j][i]);
        }
        if (judgeVec9(vec2Judge)) return false;
        vec2Judge.clear();
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){//every small matrix begin
            for(int rol=0;rol<3;rol++){
                for(int col=0;col<3;col++){
                    vec2Judge.push_back(board[i*3+rol][j*3+col]);
                }
            }
            if (judgeVec9(vec2Judge)) return false;
            vec2Judge.clear();
        }
    }
    return true;
}
int solution::strStr(string haystack, string needle) {
    int ans=-1;
    if (needle.empty()) return 0;
    string::iterator itFlag=haystack.begin();
    bool itflag=true;

    for(string::iterator sit=haystack.begin(),sitn=needle.begin();sit!=haystack.end();){
        if (*sit==*sitn)
        {
            if(itflag){itflag=false;itFlag=sit;}
            sit++,sitn++;
            if(*sitn=='\0') {
                        ans=itFlag-haystack.begin();
                        break;
                    }
        }
        else
        {
            itflag=true;
            sitn=needle.begin();
            itFlag++;
            sit=itFlag;
            ans=-1;
        }
    }

    return ans;
}


//39
bool lgr(vector<int>&a,vector<int>&b){
    if (a.size()>b.size())
        return true;
    else if(a.size()==b.size()){
        for(int i=0;i<a.size();++i){
            if (a[i]>b[i]) return true;
            else if(a[i]<b[i]) return false;
        }
        return false;
    }else{
        return false;
    }
}
vector<vector<int>> solution::combinationSum(vector<int>& candidates, int target) {
    //2,3,6,7   7
    vector<vector<int>> ans;
    int sz=candidates.size();
    if (sz==0) return ans;

    vector<int> ansTmp;

    for(int i=0;i<sz;++i){
        int leftNum=target-candidates[i];
        if(leftNum>0){
            vector<vector<int>> ansTemp1=combinationSum(candidates, leftNum);
            for(int j=0;j<ansTemp1.size();++j)
            {
                ansTemp1[j].push_back(candidates[i]);
                sort(ansTemp1[j].begin(),ansTemp1[j].end());
            }
            ans.insert(ans.end(),ansTemp1.begin(),ansTemp1.end());
        }else if(leftNum==0){
            ansTmp.push_back(candidates[i]);
            sort(ansTmp.begin(),ansTmp.end());
            ans.push_back(ansTmp);
            sort(ans.begin(),ans.end(),lgr);
            ans.erase(unique(ans.begin(),ans.end()), ans.end());
            ansTmp.clear();
//            return ans;
        }else{
            continue;
        }
    }
    sort(ans.begin(),ans.end(),lgr);
    ans.erase(unique(ans.begin(),ans.end()), ans.end());
    return ans;
}

//40
//candidates 中的每个数字在每个组合中只能使用一次。

vector<vector<int>> combinationSum2Sub(multimap <int,bool>& candidates,int target){
    vector<vector<int>> ans;
    int sz=candidates.size();
    if (sz==0) return ans;

    vector<int> ansTmp;
    for(multimap <int,bool>::iterator i=candidates.begin();i!=candidates.end();++i){
        if(!i->second){
            int leftNum=target-i->first;
            if(leftNum>0){
                i->second=true;
                vector<vector<int>> ansTemp1=combinationSum2Sub(candidates, leftNum);
                i->second=false;
                for(int j=0;j<ansTemp1.size();++j)
                {
                    ansTemp1[j].push_back(i->first);
                    sort(ansTemp1[j].begin(),ansTemp1[j].end());
                }
                ans.insert(ans.end(),ansTemp1.begin(),ansTemp1.end());
            }else if(leftNum==0){
                ansTmp.push_back(i->first);
                sort(ansTmp.begin(),ansTmp.end());
                ans.push_back(ansTmp);
                sort(ans.begin(),ans.end(),lgr);
                ans.erase(unique(ans.begin(),ans.end()), ans.end());
                ansTmp.clear();
            }else{
                continue;
            }
        }
    }
    sort(ans.begin(),ans.end(),lgr);
    ans.erase(unique(ans.begin(),ans.end()), ans.end());
    return ans;
}
vector<vector<int>> solution::combinationSum2(vector<int>& candidates, int target){
    //10,1,2,7,6,1,5   8
    vector<vector<int>> ans;
    int sz=candidates.size();
    if (sz==0) return ans;

    multimap <int,bool> cddts;
    vector<int> ansTmp;
    for(int i=0;i<sz;++i){
        cddts.insert(pair<int,bool>(candidates[i],false));
    }

    for(multimap <int,bool>::iterator it=cddts.begin();it!=cddts.end();++it){
        int leftNum=target-it->first;
        if(leftNum>0){
            it->second=true;
            vector<vector<int>> ansTemp1=combinationSum2Sub(cddts,leftNum);
            it->second=false;
            for(int j=0;j<ansTemp1.size();++j)
            {
                ansTemp1[j].push_back(it->first);
                sort(ansTemp1[j].begin(),ansTemp1[j].end());
            }
            ans.insert(ans.end(),ansTemp1.begin(),ansTemp1.end());
        }else if(leftNum==0){
            ansTmp.push_back(it->first);
            sort(ansTmp.begin(),ansTmp.end());
            ans.push_back(ansTmp);
            sort(ans.begin(),ans.end(),lgr);
            ans.erase(unique(ans.begin(),ans.end()), ans.end());
            ansTmp.clear();
        }else{
            continue;
        }
    }
    sort(ans.begin(),ans.end(),lgr);
    ans.erase(unique(ans.begin(),ans.end()), ans.end());
    return ans;
}

//41
int solution::firstMissingPositive(vector<int>& nums){
    if(nums.empty()) return 1;
    if(nums.size()==1)return (nums[0]==1)?2:1;

    sort(nums.begin(),nums.end());
    if(nums[0]>1) return 1;

    int target=-1;
    for(int i=0;i<nums.size();++i){
        if(nums[i]<=0) continue;
        else if(nums[i]==1){
            target=2;
        }
        else{
            if(target<0)target=1;
            else{
                if(target==nums[i]){
                    target++;
                }else if(target<nums[i]){
                    return target;
                }else continue;
            }
        }
    }
    if(target==-1) return 1;
    else return target;
}

//42
int solution::trap(vector<int>& height) {
    if(height.size()<2) return 0;

    int areasSum=0;
    int leftMax=0;
    int rightMax=leftMax;
    vector<int>::iterator right,left;
    left=height.begin();
    right=height.end()-1;
    while (left<right) {
        if(*left<*right){
            if(*left>leftMax){
                leftMax=*left;
            }else{
                areasSum+=(leftMax-*left);
            }
            ++left;
        }else{
            if(*right>rightMax){
                rightMax=*right;
            }else{
                areasSum+=(rightMax-*right);
            }
            --right;
        }
    }
    return areasSum;
}

//43,v1.0 cannot succeed
string multiply1(string num1, string num2) {
    int a=0,b=0;

    for(int i=0;i<num1.size();i++)
    {
        a=(num1[i]-'0')+a*10;
    }
    for(int i=0;i<num2.size();i++)
    {
        b=(num2[i]-'0')+b*10;
    }
    int c=a*b;
    string ans,d;
    while(c){
        d.push_back(c%10+'0');
        d.insert(d.end(),ans.begin(),ans.end());
        ans=d;
        d.clear();
        c/=10;
    }
    return ans;
}
//43,v2.0
string solution::multiply(string num1, string num2) {
    int l1=num1.size(),l2=num2.size();

    string res(1,'0');
    if(l1==1&&num1[0]=='0') return res;
    if(l2==1&&num2[0]=='0') return res;

    string ans(l1+l2,'0');
    int ansij;
    for(int j=l2-1;j>-1;--j){
        for(int i=l1-1;i>-1;--i){
            ansij=(num2[j]-'0')*(num1[i]-'0')+(ans[i+j+1]-'0');
            ans[i+j]+=ansij/10;
            ans[i+j+1]=ansij%10+'0';
        }
    }
    for(string::iterator i=ans.begin();i!=ans.end();){
        if(*i=='0') i=ans.erase(i);
        else break;
    }
    return ans;
}

//44
bool solution::isMatch(string s, string p) {
    //"dfimde",num2 = "*de";
    string::iterator i=p.begin();
    string::iterator lastp=p.end(),lasts=s.end();

    for(string::iterator j=s.begin();j!=s.end();){
        if(*i=='*'){
            i++;
            if(i==p.end()) return true;
            lastp=i;
            lasts=j;
        }else if(*i=='?'||*i==*j){
            i++;
            j++;
        }else if(lasts!=s.end()){
            i=lastp;
            j=++lasts;
        }
        else return false;
    }
//    while (*i=='*') {
//        i++;
//    }
    if(i==p.end()) return true;
    return false;
}

//45
vector<vector<int> > jump1(vector<int>::iterator it,vector<int>& nums){
    vector<vector<int> > ans,tmp;
    if(it!=nums.end()-1){
        for(int j=1;j<=*it;j++){
            if(it+j!=nums.end())
            {
                tmp=jump1(it+j,nums);
                for(int k=0;k<tmp.size();k++) tmp[k].push_back(*it);
                ans.insert(ans.end(),tmp.begin(),tmp.end());
                tmp.clear();
            }else break;
        }
    }else{
        vector<int> tmp(1,*it);
        ans.push_back(tmp);
    }
    return ans;
}
int jump(vector<int>& nums){
    if(nums.size()==1&&nums[0]==0) return 0;
    vector<int>::iterator it=nums.begin();
    vector<vector<int> > tmp,ans;
    for(int j=1;j<=*it;j++){
        if(it+j!=nums.end())
        {
            tmp=jump1(it+j,nums);
            ans.insert(ans.end(),tmp.begin(),tmp.end());
        }else break;
    }
    int szMin=INT_MAX;
    if(ans.empty()) return 1;
    for(int i=0;i<ans.size();++i){
        szMin=szMin<ans[i].size()?szMin:ans[i].size();
    }
    return szMin;
}
int solution::jump(vector<int>& nums){
    if(nums.size()==1) return 0;

    vector<int>::iterator it=nums.begin();
    int szMax=0,step=0;
    while(it!=nums.end()){
        int j=1;
        for(;j<=*it;j++){
            if(it+j!=nums.end()){
                szMax=szMax>*(it+j)?szMax:*(it+j);
            }else{
                szMax=j-1;
                break;
            }
        }
        step++;
        it+=szMax;
        if(szMax==0|| it==nums.end()) return ++step;
        szMax=0;
    }
    return step;
}
//46
vector<vector<int>> solution::permute(vector<int>& nums) {
    //1,2,   3
    vector<vector<int>> ans;
    if(nums.size()<2){
        ans.push_back(nums);
        return ans;
    };

    vector<int> tmp;
    tmp.push_back(nums[0]);
    tmp.push_back(nums[1]);
    ans.push_back(tmp);
    swap(tmp[0],tmp[1]);
    ans.push_back(tmp);
    tmp.clear();

    for(int n=2;n<nums.size();++n){
        int szAns=ans.size();
        for(int i=0;i<szAns;++i){//2
            ans[i].push_back(nums[n]);
            tmp=ans[i];
            int sz=tmp.size()-1;
            for(int j=0;j<sz;++j){
                vector<int> tmp1=tmp;
                swap(tmp1[j],tmp1[sz]);
                ans.push_back(tmp1);
            }
        }
    }
    sort(ans.begin(),ans.end(),lgr);
    ans.erase(unique(ans.begin(),ans.end()), ans.end());//47
    return ans;
}

//n*n matrix T
void rotate1(vector<vector<int>>& matrix) {
    int sz=matrix[0].size();
    if(sz<2) return;

    int count=0;
    while (sz>1) {
        for(int i=1;i<sz;++i){
            swap(matrix[0][i+count],matrix[i+count][0]);
        }
        count++;
        sz-=2;
    }
    return;
}
void solution::rotate(vector<vector<int>>& matrix) {
    int sz=matrix[0].size();
    if(sz<2) return;

    int count=0;
    int start,end,j;
    while (sz>1) {
        vector<int> tmp=matrix[count];
        start=count;
        end=sz+count;
        j=end-1;
        for(int i=start;i<end-1;++i){
            matrix[start][i]=matrix[j--][start];//up line
        }
        for(int i=start+1;i<end;++i){
            matrix[i][start]=matrix[end-1][i];//left line
        }
        j=end-2;
        for(int i=start+1;i<end;++i){
            matrix[end-1][i]=matrix[j--][end-1];//down line
        }
        for(int i=start;i<end;++i){
            matrix[i][end-1]=tmp[i];//right line
        }
        ++count;
        sz-=2;
    }
    return;
}

bool checkStringEquals(string a,string b){
    if(a.size()!=b.size()) return false;
    //fun 1
    sort(b.begin(),b.end());
    return (a==b)? true:false;
}
vector<vector<string> > groupAnagrams(vector<string>& strs) {

    vector<vector<string> > ans;
    int n=strs.size();
    if (n<2){
        ans.push_back(strs);
        return ans;
    }
    vector<string> tmp;
    tmp.push_back(strs[0]);
    sort(strs[0].begin(),strs[0].end());

    map<string,vector<string>> res;
    res.insert(pair<string,vector<string>>(strs[0],tmp));
    tmp.clear();

    bool StringInAns=false;
    for(int i=1;i<n;++i){
        for(map<string,vector<string>>::iterator j=res.begin();j!=res.end();++j){
            StringInAns=checkStringEquals(j->first,strs[i]);
            if(StringInAns){
                j->second.push_back(strs[i]);
                break;
            }
        }
        if(!StringInAns){
            tmp.push_back(strs[i]);
            sort(strs[i].begin(),strs[i].end());
            res.insert({strs[i],tmp});
            tmp.clear();
        }
        StringInAns=false;
    }
    for(map<string,vector<string>>::iterator j=res.begin();j!=res.end();++j){
        ans.push_back(j->second);
    }
    return ans;
}

vector<vector<string>> solution::groupAnagrams(vector<string>& strs) {
    map<string,vector<string> > ma;
    vector<vector<string>> res;
    for(auto str:strs){
        string tmp = str;
        sort(tmp.begin(),tmp.end());
        ma[tmp].push_back(str);
    }
    for(const auto& m:ma)
        res.push_back(m.second);
    return res;
}
//50,fun 1
double myPow(double x, int n) {
    double ans=1.0;
    int count=abs(n);
    while(count){
        ans*=x;
        --count;
    }
    return (n>0)?ans:1/ans;
}
double myPow1(double x, long long &count) {
    double ans=1.0;
    while(count){
        if(count%2){
            --count;
            ans=x*myPow1(x,count);
        }else{
            count/=2;
            double tmp=myPow1(x,count);
            ans=tmp*tmp;
        }
    }
    return ans;
}
double solution::myPow(double x, int n) {
    double ans=1.0;
    long long count = n;
    if (count < 0) {
        x = 1 / x;
        count = -count;
    }
    while(count){
        if(count%2){
            --count;
            ans=x*myPow1(x,count);
        }else{
            count/=2;
            double tmp=myPow1(x,count);
            ans=tmp*tmp;
        }
    }
    return ans;
}

vector<int> solution::spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row=matrix.size();
    if(row<1) return ans;
    if(row==1) return matrix[0];
    int col=matrix[0].size();
    if (col==1){
        for (int i=0;i<row;i++){
            ans.push_back(matrix[i][0]);
        }
        return ans;
    }

    int loop=0;
    int col_start=loop,col_end=col-loop,row_start=loop,row_end=row-loop;
    while (col_end>col_start && row_end>row_start) {
        for(int i=col_start;i<col_end;++i){
            ans.push_back(matrix[row_start][i]);//up line
        }
        for(int i=row_start+1;i<row_end-1;++i){
            ans.push_back(matrix[i][col_end-1]);//right line
        }
        for(int i=col_end-1;i>col_start;--i){
            ans.push_back(matrix[row_end-1][i]);//down line
        }
        for(int i=row_end-1;i>row_start;--i){
            ans.push_back(matrix[i][col_start]);//left line
        }
        ++loop;
        col_start=loop;
        col_end=col-loop;
        row_start=loop;
        row_end=row-loop;
    }
    return ans;
}


bool bgrRange(vector<int> &a,vector<int>&b){
    return (a[0]<b[0])?true:false;
}
vector<vector<int>> solution::merge(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    if(intervals.empty()) return ans;
    sort(intervals.begin(),intervals.end(),bgrRange);

    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=(ans.back())[1]) {
            (ans.back())[1]=intervals[i][1]>(ans.back())[1]?intervals[i][1]:(ans.back())[1];
            (ans.back())[0]=intervals[i][0]<(ans.back())[0]?intervals[i][0]:(ans.back())[0];
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
//62
int uniquePaths(int m, int n) {
    if(m <= 0 || n <= 0)
        return 0;
    else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
        return 1;
    else if(m == 2 && n == 2)
        return 2;
    else if((m == 3 && n == 2) || (m == 2 && n == 3))
        return 3;
    int paths = 0;
    paths += uniquePaths(m-1,n);
    paths += uniquePaths(m,n-1);
    return paths;
}
static int a[101][101]={0};
int solution::uniquePaths(int m, int n) {
    if(m <= 0 || n <= 0)
        return 0;
    else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
        return 1;
    else if(m == 2 && n == 2)
        return 2;
    else if((m == 3 && n == 2) || (m == 2 && n == 3))
        return 3;
    if(a[m][n] > 0)
        return a[m][n];
    a[m-1][n] =  uniquePaths(m-1,n);
    a[m][n-1] =  uniquePaths(m,n-1);
    a[m][n] = a[m-1][n]+a[m][n-1];

    return a[m][n];;
}

//73
void solution::setZeroes(vector<vector<int>>& matrix) {
    int row=matrix.size();
    if(row==0) return;
    int col=matrix[0].size();
    int a[row+col]={0};

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(matrix[i][j]==0){
                a[i]=1;
                a[row+j]=1;
            }
        }
    }
    for(int i=0;i<row+col;i++)
    {
        if(a[i]==1 && i<row){
            for(int k=0;k<col;k++){
                matrix[i][k]=0;
            }
        }
        if(a[i]==1&& i>=row){
            for(int k=0;k<row;k++){
                matrix[k][i-row]=0;
            }
        }
    }
    return;
}
//75
void solution::sortColors(vector<int>& nums) {
    vector<int>::iterator left=nums.begin(),right=nums.end()-1;
    for(vector<int>::iterator it=left;left<right,it<=right;it++){
        if(*it==0) {
            swap(*it,*left);
            left++;
        }else if(*it==2){
            swap(*it,*right);
            right--;
            it--;
        }
    }
    return;
}
string solution::minWindow(string s, string t) {
//"ADOBECODEBANC",t="ABC";
    unordered_map<char,int> mode,window;
    for (char c : t) mode[c]++;

    int matchCount=0, start=0,minLen = INT_LEAST32_MAX;
    string::iterator ileft=s.begin();
    string::iterator iright=ileft;
    while(iright!=s.end()){
        if(mode.count(*iright)){
            window[*iright]++;
            if(window[*iright]==mode[*iright]) matchCount++;
        }
        iright++;

        while (matchCount==mode.size()) {
            if(iright-ileft<minLen){
                start=ileft-s.begin();
                minLen=iright-ileft;
            }
            if(mode.count(*ileft)){
                window[*ileft]--;
                if(window[*ileft]<mode[*ileft]) matchCount--;
            }
            ileft++;
        }
    }
    return minLen==INT_LEAST32_MAX?"":s.substr(start,minLen);
}
vector<vector<int> > GetSubsets(vector<int>& nums,int n){
    vector<int> tmp;
    vector<vector<int> > res;
    for(int i=0;i<n;i++){

    }
    return res;
}
vector<vector<int> > solution::subsets(vector<int>& nums) {
    vector<int> tmp;
    vector<vector<int> > res;
    res.push_back(tmp);

    if(nums.empty()) return res;

    for(int i=0;i<nums.size();i++){
        int n=res.size();
        for(int j=0;j<n;j++){
            tmp=res[j];
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            tmp.clear();
        }
    }
    return res;
}
//79
bool checkExist(vector<vector<char>>& board,bool *a,string word,int i,int j,int k){
    int row=board.size();

    bool ext=false;
    if(board[j][k]==word[i]) {
        if(i==word.size()-1) return true;
        a[j*row+k]=true;
        if(k<board[0].size()-1) {
            if(!a[j*row+k+1]) ext=checkExist(board,a,word,i+1,j,k+1);
            else ext=false;
        }

        if(ext) return true;
        else if(j<board.size()-1) {
            if(!a[(j+1)*row+k]) ext=checkExist(board,a,word,i+1,j+1,k);
            else ext=false;
        }

        if(ext) return true;
        else if(k>0) {
            if(!a[j*row+k-1]) ext=checkExist(board,a,word,i+1,j,k-1);
            else ext=false;
        }
        if(ext) return true;

        if(j>0) {
            if(!a[(j-1)*row+k]) ext=checkExist(board,a,word,i+1,j-1,k);
            else ext=false;
        }
        return ext;
    } else return false;
}
bool solution::exist(vector<vector<char>>& board, string word) {
    bool ext=false;
    int row=board.size();
    if(row<1) return false;
    int col=board[0].size();

    bool TALLA[row][col]={false};
    bool TF[row][col]={false};

    for(int j=0;j<row;++j){
        for(int k=0;k<col;++k){
            if(board[j][k]==word[0]){
                ext=checkExist(board,&TF[0][0],word,0,j,k);
                if(ext) return ext;
                else memcpy(TF,TALLA,row*col);
            }
        }
    }
    return false;
}
int getArea(vector<int>& heights,int beg,int end){
    if(beg==end) return 0;
    else if(beg==end-1) return heights[beg];

    int minH=INT_LEAST32_MAX,idx;
    int area=0;
    for(int i=beg;i<end;i++){
        if(heights[i]<minH){
            minH=heights[i];
            idx=i;
        }
    }
    area=minH*(end-beg);
    int areaTmp=getArea(heights,beg,idx);
    area=areaTmp>area?areaTmp:area;
    areaTmp=getArea(heights,idx+1,end);
    area=areaTmp>area?areaTmp:area;
    return area;
}
int solution::largestRectangleArea(vector<int>& heights) {
    return getArea(heights,0,heights.size());
}



int solution::numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}

void preorder(TreeNode* p,vector<int>& res){
    if(p){
        preorder(p->left,res);
        res.push_back(p->val);
        preorder(p->right,res);
    }
}
vector<int> solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root,ans);
    return ans;
}

bool isValid(TreeNode* root,long left,long right){
    if(!root) return true;
    else if(root->val<=left||root->val>=right) return false;

    return isValid(root->left,left,root->val)&&isValid(root->right,root->val,right);
}
bool solution::isValidBST(TreeNode* root) {
    return isValid(root,INT_FAST32_MIN,INT_FAST32_MAX);
}
vector<vector<int>> solution::levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<TreeNode*> qT;
    qT.push(root);

    while (!qT.empty()) {
        vector<int> li;
        int n=qT.size();
        while (n--) {
            TreeNode* leaf =qT.front();
            li.push_back(leaf->val);
            qT.pop();
            if(leaf->left) qT.push(leaf->left);
            if(leaf->right) qT.push(leaf->right);
        }
        ans.push_back(move(li));
    }
    return ans;
}
vector<vector<int>> solution::levelOrderBFS(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<TreeNode*> qT,nxtqT;
    qT.push_back(root);
    vector<int> li;
    while (!qT.empty()) {
        li.clear();
        nxtqT.clear();

        int n=qT.size();
        for(int i=0;i<n;i++) {
            TreeNode* leaf =qT[i];
            li.push_back(leaf->val);

            if(leaf->left) nxtqT.push_back(leaf->left);
            if(leaf->right) nxtqT.push_back(leaf->right);
        }
        ans.push_back(move(li));
        qT=nxtqT;
    }
    return ans;
}

void DFS(TreeNode* leaf,int level,vector<vector<int>> &ans){
    if(leaf){
        if(level>=ans.size())
        {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        ans[level].push_back(leaf->val);
        if(leaf->left) DFS(leaf->left,level+1,ans);
        if(leaf->right) DFS(leaf->right,level+1,ans);
    }
    return;
}
vector<vector<int>> solution::levelOrderDFS(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    DFS(root,0,ans);

    return ans;
}


vector<vector<int> > solution::zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<TreeNode*> qT,nxtqT;
    qT.push_back(root);
    vector<int> li;
    int level=1;
    while (!qT.empty()) {
        li.clear();
        nxtqT.clear();

        int n=qT.size();
        for(int i=0;i<n;i++) {
            TreeNode* leaf =qT[i];
            li.push_back(leaf->val);

            if(leaf->left) nxtqT.push_back(leaf->left);
            if(leaf->right) nxtqT.push_back(leaf->right);
        }
        if(level%2==0) {
            vector<int> liReverse;
            for(int i=li.size()-1;i>=0;i--){
                liReverse.push_back(li[i]);
            }
            ans.push_back(move(liReverse));
        }else{
            ans.push_back(move(li));
        }
        qT=nxtqT;
        if (qT.empty()) level=0;
        ++level;
    }
    return ans;
}
//digui
bool DFSisSymmetric(TreeNode* left,TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right ) return false;
    if(left->val!=right->val) return false;

    return (DFSisSymmetric(left->left,right->right) && DFSisSymmetric(left->right,right->left));
}
bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return DFSisSymmetric(root->left,root->right);
}
bool solution::isSymmetric(TreeNode* root) {
    if(!root) return false;

    vector<TreeNode*> NodeLi,NodeNextL;
    vector<int> Li;
    NodeLi.push_back(root);
    int level=1;
    while (!NodeLi.empty()) {
        Li.clear();
        NodeNextL.clear();

        for(int i=0;i<NodeLi.size();i++){
            TreeNode* leaf=NodeLi[i];
            if(leaf) Li.push_back(leaf->val);

            if(leaf->left) NodeNextL.push_back(leaf->left);
            if(leaf->right) NodeNextL.push_back(leaf->right);
        }
        int sz=Li.size();
        if(level>1 && sz%2) return false;
        for(int i=0;i<sz/2;i++){
            if(Li[i]!=Li[sz-i-1]) return false;
        }
        Li.clear();
        NodeLi=NodeNextL;
    }
    return true;
}

//function 1
int DFSDepth(TreeNode* root){
    if(!root) return 0;
    int leftMaxDepth=DFSDepth(root->left);
    int rightMaxDepth=DFSDepth(root->right);
    return max(leftMaxDepth,rightMaxDepth)+1;
}
int maxDepth(TreeNode* root) {
    int depth=0;
    if(!root) return depth;

    return DFSDepth(root);
}
//function 2
int DFSDepth(TreeNode* left,TreeNode* right){
    int depth =0;
    if (!left && !right) return depth+1;
    else if (!left && right) depth=DFSDepth(right->left,right->right);
    else if (left&&!right) depth=DFSDepth(left->left,left->right);
    else  {
       int dleft=DFSDepth(left->left,left->right);
       int dright=DFSDepth(right->left,right->right);
       depth=dleft>dright?dleft:dright;
    }
    return depth+1;
}
//int maxDepth(TreeNode* root) {
//    int depth=0;
//    if(!root) return depth;

//    return DFSDepth(root->left,root->right);
//}
//function 3
int solution::maxDepth(TreeNode* root) {
    int depth=0;
    if(!root) return depth;

    vector<TreeNode*> NodeLi,NodeNextL;
    NodeLi.push_back(root);
    while (!NodeLi.empty()) {
        depth++;
        NodeNextL.clear();
        for(int i=0;i<NodeLi.size();i++){
            TreeNode* node=NodeLi[i];
            if(node->left) NodeNextL.push_back(node->left);
            if(node->right) NodeNextL.push_back(node->right);
        }
        NodeLi=NodeNextL;
    }

    return depth;
}

TreeNode* buildTree1(vector<int>::iterator preIt,vector<int>& preorder,vector<int>::iterator inbeg,vector<int>::iterator inEnd,vector<int>& inorder){
    TreeNode* root=NULL;
    if(preIt!=preorder.end()){
        root=new TreeNode(*preIt);
        root->left=NULL;
        root->right=NULL;

        vector<int>::iterator it=inbeg;
        int rtindx=0;
        for(;it!=inEnd;it++){
            if(*it==*preIt){
                break;
            }
            rtindx++;
        }
        preIt++;
        if(it==inbeg) root->left=NULL;
        else root->left=buildTree1(preIt,preorder,inbeg,it,inorder);
        vector<int>::iterator itR=preIt+rtindx;
        it++;

        if(it==inEnd || itR==preorder.end()) root->right=NULL;
        else root->right=buildTree1(itR,preorder,it,inEnd,inorder);
    }
    return root;
}


TreeNode* solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()) return NULL;
    if(preorder.size()!=inorder.size()) return NULL;

    return buildTree1(preorder.begin(),preorder,inorder.begin(),inorder.end(),inorder);
}

void preOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
    return;
}
void inOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
    return;
}
void aftOrder(TreeNode* root,vector<int> &ans){
    if(!root) return;
    aftOrder(root->left,ans);
    aftOrder(root->right,ans);
    ans.push_back(root->val);
    return;
}
vector<int> solution::preOrder1(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    preOrder(root,ans);
    return ans;
}
vector<int> solution::inOrder1(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    inOrder(root,ans);
    return ans;
}
vector<int> solution::aftOrder1(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    aftOrder(root,ans);
    return ans;
}
//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树
TreeNode* sortedArrToBST(vector<int>::iterator itbeg,vector<int>::iterator itend,vector<int>& nums){
    TreeNode* root=NULL;
    if(itbeg==itend) return root;

    vector<int>::iterator it=itbeg+(itend-itbeg)/2;
    root=new TreeNode(*it);
    root->left=sortedArrToBST(itbeg,it,nums);
    it++;
    root->right=sortedArrToBST(it,itend,nums);
    return root;
}
TreeNode* solution::sortedArrayToBST(vector<int>& nums) {
    TreeNode* root=NULL;
    if(nums.empty()) return root;

    root=sortedArrToBST(nums.begin(),nums.end(),nums);
    return root;
}

//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
Node* connect1(Node* root) {
    if(!root) return root;

    vector<Node*> Li,LiNext;
    Li.push_back(root);

    while (!Li.empty()) {
        LiNext.clear();
        int n=Li.size();
        for(int i=0;i<n;i++){
            if(i==n-1) Li[i]->next=NULL;
            else Li[i]->next=Li[i+1];

            if(Li[i]->left) LiNext.push_back(Li[i]->left);
            if(Li[i]->right) LiNext.push_back(Li[i]->right);
        }
        Li=LiNext;
    }
    return root;
}
Node* solution::connect(Node* root) {//NB
    if (!root) return root;
    Node * left = root->left;
    Node * right = root->right;
    while(left) {
        left->next = right;
        left = left->right;
        right = right->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
}


vector<vector<int>> generate(int numRows){//my
    vector<vector<int>> ans;
    if(numRows<1) return ans;

    vector<int> Li;
    Li.push_back(1);
    if(numRows==1){
        ans.push_back(Li);
        return ans;
    }
    if(numRows==2){
        ans.push_back(Li);
        Li.push_back(1);
        ans.push_back(Li);
        return ans;
    }
    ans.push_back(Li);
    Li.push_back(1);
    ans.push_back(Li);

    vector<int> li;
    for(int j=2;j<numRows;j++){
        li.clear();
        li.push_back(1);
        for(int i=2;i<j+1;i++){
            li.push_back(Li[i-2]+Li[i-1]);
        }
        li.push_back(1);
        ans.push_back(li);
        Li=li;
    }
    return ans;
}

vector<vector<int>> solution::generate(int numRows){//
    vector<vector<int>> ans(numRows);
    if(numRows<1) return ans;

    ans[0].push_back(1);
    for(int i=1;i<numRows;i++){
        ans[i].push_back(1);
        for(int j=1;j<i;j++){
            ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
        }
        ans[i].push_back(1);
    }
    return ans;
}

//function1
int maxProfit(vector<int>& prices) {
    int res=0;
    if(prices.size()<2) return res;

    int Mx=INT_MIN,MxIndx=-1;
    int Mn=INT_MAX,MnIndx=-1;
    for(int i=0;i<prices.size();i++){
        if(prices[i]>Mx ||MnIndx>MxIndx) {
            Mx=prices[i];
            MxIndx=i;
        }

        if(prices[i]<Mn){
            Mn=prices[i];
            MnIndx=i;
        }
        if(MxIndx>0 && MnIndx>=0 && MnIndx<MxIndx) res=(prices[MxIndx]-prices[MnIndx])>res?(prices[MxIndx]-prices[MnIndx]):res;
    }
    return res;
}
//function2
int maxProfit1(vector<int>& prices) {
    int res=0;
    if(prices.size()<2) return res;

    int diff=0,lastdiff=0;
    for(int i=1;i<prices.size();i++){
        diff=prices[i]-prices[i-1];
        lastdiff=max(0,lastdiff+diff);
        res=max(res,lastdiff);
    }
    return res;
}
int solution::maxProfit(vector<int>& prices) {
    int res=0;
    if(prices.size()<2) return res;

    int diff=0,lastdiff=0;
    for(int i=1;i<prices.size();i++){
        diff=prices[i]-prices[i-1];
        if(diff>0){
            lastdiff=max(0,lastdiff+diff);
            res=max(res,lastdiff);
        }
    }
    return res;
}
int maxPathSum1(TreeNode* root, int &val)
{
    if (root == nullptr) return 0;
    int left = maxPathSum1(root->left, val);
    int right = maxPathSum1(root->right, val);
    int lmr = root->val + max(0, left) + max(0, right);
    int ret = root->val + max(0, max(left, right));
    val = max(val, max(lmr, ret));
    return ret;
}

int solution::maxPathSum(TreeNode* root) {
    int val = INT_MIN;
    maxPathSum1(root, val);
    return val;
}


bool solution::isPalindrome(string s){
    if(s.empty()) return true;

    int left=-1,right =-2;
    for(string::iterator beg=s.begin(),end=s.end()-1;beg<end;){
        left=-1;right =-2;
        while(left<0){
            if(*beg>='a' && *beg<='z') left=*beg-'a';
            else if(*beg-'A'>=0 && *beg-'Z'<=0) left=*beg-'A';
            else if(*beg-'0'>=0&&*beg-'9'<=0) left=*beg-'0'+26;
            else {
                left=-1;beg++;
            }
            if(!*beg) return true;
        }
        while(right<0){
            if(*end-'a'>=0 && *end-'z'<=0) right=*end-'a';
            else if(*end-'A'>=0 && *end-'Z'<=0) right=*end-'A';
            else if(*end-'0'>=0&&*end-'9'<=0) right=*end-'0'+26;
            else {
                right=-2;
                end--;
            }
            if(!*end) return true;
        }
        if(left!=right) return false;
        beg++;
        end--;
    }
    return true;
}


int checkIfWordInList(string &Word, vector<string>& wordList){
    for(int i=0;i<wordList.size();i++){
        if(Word==wordList[i]) return i;
    }
    return -1;
}
int ladderLengthI(string &beginWord, string &endWord, vector<string>& wordList,int& step)
{
    if (checkIfWordInList(endWord,wordList)<0) return -1;
    int j=checkIfWordInList(beginWord,wordList);
    if (j>=0) {
        step++;
        return j;
    }
    else return -1;
}


int solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (checkIfWordInList(endWord,wordList)<0) return 0;

    string s=beginWord;
    int n=0,step=0,i=0;
    while(beginWord!=endWord&&i!=endWord.size()){
        for(;i<endWord.size();i++){
            s[i]=endWord[i];
            n=ladderLengthI(s,endWord,wordList,step);
            if(n>=0) {
                s=wordList[n];
                i=0;
                break;
            }else{
                s=beginWord;
            }
        }
    }
    return step;
}

int solution::longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    sort(nums.begin(),nums.end());

    int iMx=1,iMxTemp=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[i-1]==1){
            iMxTemp++;
        }else if(nums[i]=nums[i-1]){
            ;
        }
        else {
            iMx=max(iMx,iMxTemp);
            iMxTemp=1;
        }
    }
    return max(iMx,iMxTemp);
}


void solution::solve(vector<vector<char>>& board) {

}

//55
bool solution::canJump(vector<int>& nums) {
    int farMost = 0;
    for(int i = 0;i<nums.size();i++){
        if(i > farMost) return false;
        if(i+nums[i] > farMost) farMost = i+nums[i];
    }
    return true;    
}

//5....too difficult
string solution::longestPalindrome(string s) {
    if(s.size() == 1) return s;

    string ans;

    int len = 0;
    bool pushed = false;
    for(string::iterator i = s.begin(); i !=s.end(); i++){
        string::iterator j = ++i;
        i--;
        for(;j!=s.end();j++){
            if(*i == *j && (j-i > len) && !pushed){
                pushed = false;
                ans.clear();
                ans.insert(ans.end(),i,++j); 
                len = ans.size();                
            }
            if(pushed && *i != *j){
                pushed = true;
                break;
            }
        }
    }

    if(len == 0) ans.push_back(s[0]);
    return ans;
}

//15
vector<vector<int> > solution::threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    if(nums.size() < 3) return ans;

    sort(nums.begin(),nums.end());

    int left, right;
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        left = i+1;
        right = nums.size()-1;
        if(nums[i] > 0) break;

        while(left < right){
            int leftValue = nums[left], rightValue = nums[right];  
            int temp = nums[i] + leftValue + rightValue;
            if(temp == 0){
                vector<int> temp1 = {nums[i], leftValue, rightValue};
                ans.push_back(temp1);
                
                while(nums[left] == leftValue && left<right){
                    left++;
                }
               
                while(nums[right] == rightValue && left<right){
                    right--;
                }
            }else if(temp > 0) right --;
            else left++;            
        }
    }
    return ans;
}
//18
vector<vector<int>> solution::fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if(nums.size() < 4) return ans;

    sort(nums.begin(),nums.end());

    int left, right;
    
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1;j<nums.size();j++){            
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            left = j+1;
            right = nums.size()-1;

            while(left < right){
                int leftValue = nums[left], rightValue = nums[right];  
                int temp = nums[i] + nums[j] + leftValue + rightValue;
                if(temp == target){
                    vector<int> temp1 = {nums[i], nums[j], leftValue, rightValue};
                    ans.push_back(temp1);
                    
                    while(nums[left] == leftValue && left<right){
                        left++;
                    }
                
                    while(nums[right] == rightValue && left<right){
                        right--;
                    }
                }else if(temp > target) right --;
                else left++;            
            }
        }        
    }
    return ans;
}

//19
//solution 1. 两步扫描
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int listSize = 0;

    ListNode* p = head;
    while (p)
    {
        listSize++;
        p = p->next;
    }
    if(listSize < n) return head;

    p = head;

    int i = 1;
    while (i < listSize - n)
    {
        i++;
        p = p->next;
    }
    
    //delete
    ListNode* temp = p->next;
    if(temp == NULL){
        p->next = NULL;
    }else{
        p->next = temp->next;
    }

    return head->next;
}


//solution 2. 一步扫描
ListNode* solution::removeNthFromEnd(ListNode* head, int n) {

    ListNode *p = new ListNode(0);
    p->next = head;
    ListNode *target = p, *temp = p;

    int i = 0;
    while (temp)
    {
        if(i<=n){
            i++;   
        }else{
            target = target->next;
        }
        temp = temp->next;
    }    
    
    //delete
    target->next = target->next->next;

    return p->next;
}

//29
int divide(int dividend, int divisor) {//time out
    if(divisor == 0) return INT32_MAX;

    long ans = 0, flag = 1;
    long dividend1 = dividend;
    long divisor1 = divisor;

    if(divisor1 < 0){
        flag = -1;
        divisor1 = - divisor1;
    }
    if(dividend1 < 0){
        flag *= -1;
        dividend1 = - dividend1;
    }
    if(divisor1 == 1){
        ans = dividend1;
    }else{
        long temp = dividend1;
        while(temp >= divisor1){
            ans++;
            divisor1+=divisor1;
        }
    }
    ans = (flag>0)?ans:-ans;

    if(ans > INT32_MAX || ans < INT32_MIN) return INT32_MAX;
    return ans;
}

int divd(int dividend, int divisor){
    if(dividend > divisor) return 0;

    int ans = 1;
    int acc = divisor;

    while(dividend - acc <= acc)
    {
        acc += acc;
        ans += ans;
    }
    return ans + divd(dividend - acc, divisor);
}
int solution::divide(int dividend, int divisor) {
    if(divisor == 1) return dividend;
    if(divisor == -1){
        if(dividend == INT32_MIN) return INT32_MAX;
        else return -dividend;
    }

    int flag = 1;
    if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)) flag = -1;

    //全负数，不会越界
    int a = (dividend > 0)?-dividend: dividend;
    int b = (divisor > 0)?-divisor: divisor;

    int ans = 0;
    ans = divd(a, b);
    ans = (flag > 0)? ans:-ans;
    if(ans > INT32_MAX || ans < INT32_MIN) return INT32_MAX;
    return ans;
}


//33
int solution::search(vector<int>& nums, int target){
    if(nums.empty()) return -1;

    int N = nums.size();
    if(N == 1) return (nums[0] == target)? 0:-1;

    int left = 0, right = N-1;    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;

        if(nums[0] <= nums[mid]){
            if(nums[0] <= target && target < nums[mid]){
                right = mid-1;
            } else{
                left = mid+1;
            }
        }else{
            if(nums[mid] < target && target<= nums[N-1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    return -1;
}

string solution::getPermutation(int n, int k) {
        
}

