#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class AllOne {
  public:
    AllOne() {
    }

    void inc(const std::string & key) {
        if (dict.find(key) == dict.end())
            dict[key] = 0;
        dict[key]++;
        if (maxkeys.empty())
            maxkeys.insert(key);
        else if (dict[key] > dict[*(maxkeys.begin())])
            maxkeys.insert(key);
        
        if (minkeys.empty())
            minkeys.insert(key);
        else if (dict[key] < dict[*minkeys.begin()])
            minkeys.insert(key);
    }

    void dec(const std::string & key) {
        if (dict.find(key) != dict.end()) {
            if (dict[key] > 1) {
                dict[key]--;
                if (dict[key] == dict[*(minkeys.begin())])
                    minkeys.insert(key);
                else if (dict[key] < dict[*(minkeys.begin())]) {
                    minkeys.clear();
                    minkeys.insert(key);
                }
            }
            else {
                dict.erase(key);
                minkeys.erase(key);
            }
        }
    }

    const std::string getMaxKey() {
        return *maxkeys.begin();
    }

    const std::string getMinKey() {
        return *minkeys.begin();
    }

  private:
    std::unordered_map<std::string,int> dict;
    std::unordered_set<std::string> maxkeys;
    std::unordered_set<std::string> minkeys;
};

int main() {
    AllOne allOne;

    allOne.inc("one");
    std::cout << "The key with max value is " << allOne.getMaxKey() << std::endl;
    std::cout << "The key with min value is " << allOne.getMinKey() << std::endl;
    allOne.inc("one");
    std::cout << "The key with max value is " << allOne.getMaxKey() << std::endl;
    std::cout << "The key with min value is " << allOne.getMinKey() << std::endl;
    allOne.inc("two");
    std::cout << "The key with max value is " << allOne.getMaxKey() << std::endl;
    std::cout << "The key with min value is " << allOne.getMinKey() << std::endl;
    allOne.dec("one");
    std::cout << "The key with max value is " << allOne.getMaxKey() << std::endl;
    std::cout << "The key with min value is " << allOne.getMinKey() << std::endl;
}
