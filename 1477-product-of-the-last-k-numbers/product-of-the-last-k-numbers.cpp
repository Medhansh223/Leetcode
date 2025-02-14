class ProductOfNumbers {
public:
vector<int>nums;
int prod=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        {
            nums.clear();
            prod=1;
        }
        else
        {
            prod=prod*num;
            nums.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        int n=nums.size();
        if(k>n)
        {
            return 0;
        }
        if(k==n)
        {
            return prod;
        }
        int num=prod/nums[n-k-1];
        return num;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */