
#include <json/json.hpp>

#include <cstdint>
#include <iostream>
#include <string>
#include <limits>

using namespace std;
using namespace json;

int main() {
    Value value;
    R"(-0.00000000001e+20)" >> value;

    cout << "Is number: " << value.is_number() << endl;
    cout << "Is double: " << value.is_double() << endl;
    cout << "Is uint: "   << value.is_uint() << endl;
    cout << "Is int: "    << value.is_int() << endl;
    cout << "Int: "       << Int(value) << endl;
    cout << "Uint: "      << Uint(value) << endl;
    cout << "Double: "    << Double(value) << endl;

    R"( " 01asafaf12.oe \u2708 \u263A \uD83D\uDE02"  )" >> value;

    cout << "Is string: " << value.is_string() << endl;
    cout << "String: '" << String(value) << "'" << endl;

    R"( true  )" >> value;

    cout << "Is bool: " << value.is_bool() << endl;
    cout << "Bool: '" << Bool(value) << "'" << endl;

    R"( false  )" >> value;

    cout << "Is bool: " << value.is_bool() << endl;
    cout << "Bool: '" << Bool(value) << "'" << endl;

    R"( null  )" >> value;

    cout << "Is null: " << value.is_null() << endl;

    cout << endl;
    cout << "Null size: " << sizeof(Null) << endl;
    cout << "Value size: " << sizeof(Value) << endl;
    cout << "Array size: " << sizeof(Array) << endl;
    cout << "Object size: " << sizeof(Object) << endl;
    cout << "String size: " << sizeof(String) << endl;
    cout << "Number size: " << sizeof(Number) << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<ptrdiff_t>::max() << endl;
    cout << "" << numeric_limits<ptrdiff_t>::min() << endl;
    cout << "" << numeric_limits<uint64_t>::digits << endl;
    cout << "" << numeric_limits<uint64_t>::digits10 << endl;
    cout << "" << numeric_limits<uint64_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<int64_t>::max() << endl;
    cout << "" << numeric_limits<int64_t>::min() << endl;
    cout << "" << numeric_limits<int64_t>::digits << endl;
    cout << "" << numeric_limits<int64_t>::digits10 << endl;
    cout << "" << numeric_limits<int64_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<uint32_t>::max() << endl;
    cout << "" << numeric_limits<uint32_t>::min() << endl;
    cout << "" << numeric_limits<uint32_t>::digits << endl;
    cout << "" << numeric_limits<uint32_t>::digits10 << endl;
    cout << "" << numeric_limits<uint32_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<int32_t>::max() << endl;
    cout << "" << numeric_limits<int32_t>::min() << endl;
    cout << "" << numeric_limits<int32_t>::digits << endl;
    cout << "" << numeric_limits<int32_t>::digits10 << endl;
    cout << "" << numeric_limits<int32_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<uint16_t>::max() << endl;
    cout << "" << numeric_limits<uint16_t>::min() << endl;
    cout << "" << numeric_limits<uint16_t>::digits << endl;
    cout << "" << numeric_limits<uint16_t>::digits10 << endl;
    cout << "" << numeric_limits<uint16_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << numeric_limits<int16_t>::max() << endl;
    cout << "" << numeric_limits<int16_t>::min() << endl;
    cout << "" << numeric_limits<int16_t>::digits << endl;
    cout << "" << numeric_limits<int16_t>::digits10 << endl;
    cout << "" << numeric_limits<int16_t>::max_digits10 << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "" << int(numeric_limits<uint8_t>::max()) << endl;
    cout << "" << numeric_limits<uint8_t>::digits << endl;
    cout << "" << numeric_limits<uint8_t>::digits10 << endl;
    cout << "" << numeric_limits<uint8_t>::max_digits10 << endl;

    cout << "" << int(numeric_limits<int8_t>::max()) << endl;
    cout << "" << numeric_limits<int8_t>::digits << endl;
    cout << "" << numeric_limits<int8_t>::digits10 << endl;
    cout << "" << numeric_limits<int8_t>::max_digits10 << endl;


}
