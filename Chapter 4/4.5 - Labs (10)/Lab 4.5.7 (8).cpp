#include <string>
#include <iostream>

void Change(std::string str, std::string &templat) {
    std::string buffer = "";
    int poz;
    std::string sub1, sub2;
    str+=',';
    for(int i = 0; i<str.size(); i++){
        if(str[i] != ','){
            buffer += str[i];
        }
        else{
            poz = buffer.find('=');
            sub1 = buffer.substr(0, poz);
            sub2 = buffer.substr(poz+1);
            while(templat.find('['+sub1+']')!=std::string::npos)
                templat.replace(templat.find('['+sub1+']'), sub1.size()+2, sub2);
            buffer = "";
        }
    }

}
int main()
{
    std::string values;
    std::getline(std::cin, values);
    std::string templat;
    std::getline(std::cin, templat);
    Change(values, templat);
    // Put values into the template
    std::cout << templat << "\n";
}
