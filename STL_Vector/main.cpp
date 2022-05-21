
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Template function to print vectors
template<class T>
void print(const vector<T> &vec)
{
    for(const auto &i: vec)
        cout << i << " ";
}

class Person
{
    friend std::ostream & operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
    
public:
    Person() = default; // compiler generated default constructor
    Person(std::string n, int a) : name{n}, age{a} {}
    
    bool operator<(const Person &rhs)
    {
        // We chose to compare less than based on age
        return this->age < rhs.age; // Note that using "this" pointer is optional
    }
    
    bool operator<(const int &rhs)
    {
        // We chose to compare less than based on age
        return this->age < rhs; // Note that using "this" pointer is optional
    }
    
    bool operator==(const Person &rhs)
    {
        return name == rhs.name && age == rhs.age;
    }
    
    
    
};

std::ostream & operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << "\nAge: " << p.age << '\n';
    return os;
}


int main()
{
    vector<int> vec1 {1,2,3};
    
    auto it = vec1.end() - 1;
    
    cout << "Capacity of vec1 = " << vec1.capacity() << endl;
    cout << "Last element = " << *it << endl;
    cout << "Max size of vec1 = " << vec1.max_size() << endl;
    
    // demonstrating invalidation of iterators
    
    vec1.push_back(4); // results in realocation
    cout << "Capacity of vec1 after pushing a new value = " << vec1.capacity() << endl;
    cout << "Last element = " << *it << endl;
    // cout << "Max size of vec1 = " << vec1.max_size() << endl; // does not change
    
    // inserting values 
    // insert 20 before 2
    // 1) find 2: returns an iterator pointing to 2's position
    auto pos = find(vec1.begin(), vec1.end(), 2);
    
    // 2) insert 20
    vec1.insert(pos, 20);
    
    print(vec1);cout << endl;
    
    // We can also insert other vectors
    vector<int> tmp {100,200,300,400};
    cout << "Inserting vector "; print(tmp); cout << " into vector "; print(vec1); cout << endl;
    cout << "After insertion vec1:";
    vec1.insert(pos, tmp.begin(), tmp.end());   
    print(vec1); cout << endl;
    
    cout << "Capacity now is " << vec1.capacity() << endl;
    // we can shrink capacity to be exactly = number of elements
    
    vec1.shrink_to_fit();
    
    cout << "Capacity after shrinking is " << vec1.capacity() << endl;
    
    // We can also reserve vectors of certain capacity
    vec1.reserve(100);
    cout << "Capacity after reserving 100 is " << vec1.capacity() << endl;
    cout << "Size is still " << vec1.size() << endl;
    
    // delete even numbers in vector
    it = vec1.begin();
    
    while(it != vec1.end())
    {
        if(*it % 2 == 0)
            vec1.erase(it);
        else
            it++;
    }
    
    cout << "After deleteing even numbers capacity is: " << vec1.capacity() << endl;
    cout << "After deleteing even numbers size is: " << vec1.size() << endl << "And vector is:\n";
    print(vec1); cout << endl;
    
    print(vec1); cout << endl;
    
    // back_inserter example
    // Insert tmp to the back of vec1
    copy(tmp.begin(), tmp.end(), back_inserter(vec1));
    cout << "After back inserting tmp into vec1, vec1 = ";
    print(vec1); cout << endl;
    
    // Conditional back_inserter
    // Copy elements from tmp to the back of vec1 if they are greater than or equal to 200
    copy_if(tmp.begin(), tmp.end(), back_inserter(vec1), [] (int x) {return x >= 200;});
    cout << "After copying elements >= 200, vec = ";
    print(vec1);cout<< endl;
    
    // combining transform with back_inserter
    vector<int> vec3 {1,2,3,4,5}; // values
    vector<int> vec4 {1,0,1,1,0,1,1}; // coeffocients
    vector<int> result;
    
    // Note that in this call the first two iterators determine the range of values
    // i.e., you can see that vec4 has more values than vec3, but that is OK since vec3.end()
    // determines the last element to be transformed 
    transform(vec3.begin(),vec3.end(),vec4.begin(),back_inserter(result),
    [] (int x, int y) {return x * y;});
    
    print(result);cout<< endl;
    
    
    // emplace methods are more efficient in adding vector elements
    vector<pair<string, int>> vec2 = {{"Ali", 22}};
    
    // create element and then copy
    pair<string, int> p {"James", 23};
    vec2.push_back(p);
    
    // create element emplace
    // Just list the values needed to initialize the objects 
    // In this case pair<string, int> needs a string followed by an int
    vec2.emplace_back("John", 24);
    
    cout << vec2.back().first << ":" << vec2.back().second << endl;
    
    
    return 0;
}