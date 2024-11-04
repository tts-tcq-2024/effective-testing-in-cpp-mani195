#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celsius) {
    if (celsius > 200) 
    {
        return 500;
    }
    return 200;
}

int alertInCelsius(float farenheit) {
    float celsius = (farenheit - 32.0) * 5.0 / 9.0;
    int returnCode = networkAlertStub(celsius);
    if (returnCode != 200) 
    {
        alertFailureCount += 1;
    }
    
    return alertFailureCount;
}

int main() {
    assert(alertInCelsius(400.5) == 1); 
    assert(alertInCelsius(303.6) == 1);
    assert(alertInCelsius(500.5) == 1); 
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
