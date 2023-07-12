#include <iostream>
#include <cmath>

#define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
typedef long long ll;

ll digits[3][4];
ll get_last_digit(ll number) {
    ll lastDigit = number % 10;
    return lastDigit;
}

ll find_digit(ll k) {
    ll grp = 0;
    ll prev_digits = 0;
    for (ll i = 0; i < 3; ++i) {
        if (digits[i][1] > k) {
            break;
        } else {
            prev_digits += digits[i][1];
            grp++;
        }
    }

    ll no_of_digits = grp + 1;
    ll relative_pos = k - prev_digits - 1;
    ll num_within_block = digits[grp][2] + (relative_pos / no_of_digits);

    ll result = num_within_block / static_cast<ll>(std::pow(10, grp - relative_pos % no_of_digits));
    return get_last_digit(result);
}

void init() {
    for (ll i = 0; i < 3; ++i) {
        digits[i][0] = 9 * static_cast<ll>(std::pow(10, i));
        digits[i][1] = digits[i][0] * (i + 1);
        digits[i][2] = static_cast<ll>(std::pow(10, i));
        digits[i][3] = static_cast<ll>(std::pow(10, i + 1)) - 1;
    }
}

int main() {
    fio;
    init();
    ll q;
    std::cin >> q;

    for (ll query = 0; query < q; ++query) {
        ll k;
        std::cin >> k;
        std::cout << find_digit(k) << "\n";
    }

    return 0;
}



// #include<iostream>
// #include<math.h>
// #define fio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
// typedef long long ll;

// ll digits[3][4];
// ll get_last_digit(ll number) {
//     // Take the modulo of the number by 10 to get the last digit
//     ll lastDigit = number % 10;
//     return lastDigit;
// }
// ll find_digit(ll k){
//   // Find the grp of k (no of digits)
//   ll grp = 0;
//   ll prev_digits = 0;
//   for(ll i = 0; i < 3; ++i){
//     if(digits[i][1] > k){
//       break;
//     } else {
//       prev_digits += digits[i][1];
//       grp++;
//     }
//   }
//   // std::cout<<"Digit: "<<k<<"\n";
//   // std::cout<<"Grp: "<<grp<<"\n";
//   // std::cout<<"Starting Num: "<<digits[grp][2]<<"\n";
//   // std::cout<<"prev_digits: "<<prev_digits<<"\n";
//   // Find the number from the no of digits and digit position
//   ll jump = (k-prev_digits-1)/(grp+1);
//   ll result = jump + digits[grp][2];

//   return get_last_digit(result);
// }

// void init(){
//   // std::cout<<"Printing digits[3][3]\n";
//   for(ll i = 0; i < 3; ++i){
//     digits[i][0] = 9*std::pow(10,i);
//     digits[i][1] = digits[i][0]*(i+1);
//     digits[i][2] = std::pow(10, i);
//     digits[i][3] = std::pow(10, i+1)-1;
//     // for(ll j = 0; j < 3; j++){
//     //   std::cout<<"digits["<<i<<"]["<<j<<"] = "<<digits[i][j]<<"\t";
//     // }
//     // std::cout<<"\n";
//  }
// }

// int main(void){
//   fio;
//   init();
//   ll q, k;
//   std::cin>>q;
//   for(ll query = 0; query < q; ++query){
//     std::cin>>k;
//     std::cout<<find_digit(k)<<"\n";
//   }
//   return 0;
// }
