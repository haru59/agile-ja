#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

/*----これらの関数を変更する必要はありません----*/
std::vector<std::string> names {"Nick", "Lewis", "Nikos"};
bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}

std::string get_name(const std::string& name, const std::vector<std::string>& list_of_names) {
    if (contains(name, list_of_names)) {
        return name;
    } else {
        return "";
    }
}
void add_name(const std::string& name, std::vector<std::string>& list_of_names) {
    list_of_names.push_back(name);
}
int add_two(int num) {
    return num + 2;
}
double divide_by_two(double num) {
    return num / 2;
}
std::string greeting(const std::string& name, double num) {
    std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    std::cout << message << std::endl;
    return message;
}
/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/
// `my_assert` をここに定義し、以降のテストに使用してください。
void my_assert(bool expr, const std::string& msg = ""){
    if(!expr){
        throw std::runtime_error(msg);
    }
}
// `contains` 用のテスト `test_contains` を作成してください
void test_contains(){
    my_assert(contains("Nick" , names), "Error, Nick is in names");
    my_assert(!contains("AAA" , names), "Error, AAA is NOT in names");
}
// `get_name` 用のテスト `test_get_name` を作成してください
void test_get_name(){
    my_assert(get_name("Nick" , names)=="Nick", "Error, Nick is in names");
    my_assert(get_name("AAA", names)=="", "Error, AAA is NOT in names");
}

// `add_name` 用のテスト `test_add_name` を作成してください
void test_add_name(){
    std::vector<std::string> test_names{};
    int namesSize = test_names.size();
    add_name("ADD" , test_names);
    //int namesSize = test_names.size();
    //std::cout << test_names[0] << std::endl;
    my_assert(test_names[0]=="ADD","Error, ADD is added");
    my_assert(test_names.size() == namesSize + 1, "Error, Addition Error");
}

// `add_two` 用のテスト `test_add_two` を作成してください
void test_add_two(){
    my_assert(add_two(2)==4, "Error, result should be 4");
    my_assert(add_two(100)==102, "Error, result should be 102");
}

// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
void test_divide_by_two(){
    my_assert(divide_by_two(5.0)==2.5, "Error, result should be 2.5");
    my_assert(divide_by_two(10)==5, "Error, result should be 5");
}

// `greeting` 用のテスト `test_greeting` を作成してください
void test_greeting(){
    my_assert(greeting("Nick", 10.5)=="Hello, Nick. It is 10.500000 degrees warmer today than yesterday", "Error greeting");
    //std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
}


/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg` を適切に返すかどうかをチェックしてください。

// `my_assert` 用のテスト `test_my_assert_true` を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。

/*----難易度: エベレスト----*/

// 次の式全体をテストする `test_complex_greeting` を `my_assert` を使用して作成してください。式がエラーになった場合は、エラーの理由がわかるメッセージを `msg` に指定してください。

// greeting(get_name("Frosty the Snowman", {"Oatmeal", "Prancer", "Rudolph", "Andy"}), divide_by_two(add_two(2)));

int main(){
    test_contains();
    test_get_name();
    test_add_name();
    test_add_two();
    test_divide_by_two();
    test_greeting();
    //greeting("Nick" ,10.5);
    return 0;
}