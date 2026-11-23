
class ProductOfNumbers {
private:
    vector<int> array;

public:
    ProductOfNumbers() {
        array = {1};
    }

    void add(int num) {
        if (num == 0) {
            array = {1};
            return;
        }

        array.push_back(array.back() * num);
    }

    int getProduct(int k) {
        int last = array.size() - 1 - k;

        if (last < 0) {
            return 0;
        }

        return array.back() / array[last];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */