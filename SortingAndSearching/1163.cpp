#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);


    int x, n;
    cin >> x >> n;

    multiset<int> widths;
    widths.insert(x);

    multiset<int> boundaryPositions;
    boundaryPositions.insert(0);
    boundaryPositions.insert(x);
    
    for(int i = 0; i < n; i++) {
        int light;
        cin >> light;
        
        // Find the boundaryPositions to the left and right of this light
        auto right = boundaryPositions.lower_bound(light);
        auto left = right;
        --left;
        
        // Find the width that is affected
        int width = *right - *left;
        
        // Remove this width from the set
        auto w = widths.find(width);
        widths.erase(w);
        
        // Add the new two widths after breaking up
        int w1 = light - *left;
        int w2 = *right - light;
        widths.insert(w1);
        widths.insert(w2);
        
        // Insert the new boundary position
        boundaryPositions.insert(light);
        
        auto res = widths.rbegin();
        cout << *res << ' ';
    }
    
    return 0;
}