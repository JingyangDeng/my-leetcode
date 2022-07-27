//字符串流式处理
//自定义分数运算
struct Fraction {
    int nom;
    int denom;
    Fraction(int nom_, int denom_){
        nom = nom_; denom = denom_;
    }
};

Fraction add(Fraction a, Fraction b){
    int nom_tmp = a.nom * b.denom + b.nom * a.denom;
    int denom_tmp = a.denom * b.denom;
    int factor = abs(__gcd(nom_tmp, denom_tmp));
    return Fraction(nom_tmp / factor, denom_tmp / factor);
}

class Solution {
public:
    string fractionAddition(string expression) {
        Fraction ret(0, 1);
        int p = 0;
        while(p < expression.size()){
            int sign = 1;
            if(expression[p] == '-'){
                sign = -1;
                ++p;
            } else if(expression[p] == '+'){
                ++p;
            }
            int nom = 0;
            while(p < expression.size() && expression[p] != '/'){
                nom *= 10;
                nom += expression[p] - '0';
                ++p;
            }
            ++p;            
            int denom = 0;
            while(p < expression.size() && expression[p] != '+' && expression[p] != '-'){
                denom *= 10;
                denom += expression[p] - '0';
                ++p;
            }
            ret = add(ret, Fraction(sign * nom, denom));
        }
        return to_string(ret.nom) + '/' + to_string(ret.denom);
    }
};
