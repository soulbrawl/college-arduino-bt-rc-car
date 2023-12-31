// Using `#define` textually REPLACES (like a macro) the value precompiling (or during compiling, not sure)
// thus using less memory than creating `const int` variables.
// Actually in this case, using `constexpr` is even better due to Type Safety and Compile-Time optimizations.
// check out more about the info above: https://chat.openai.com/share/491c1281-0e4d-4130-83fe-ee9a1a6c0dc7

#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
constexpr uint8_t BUILTIN_LED = 13; // ESP32 = pin 2
#endif

#ifdef ENGINE_ACTIVE
constexpr uint8_t ENGINE_FL = 11; // verde
constexpr uint8_t ENGINE_FR = 8; // amarelo
constexpr uint8_t ENGINE_BL = 10; // azul pequeno
constexpr uint8_t ENGINE_BR = 9; // azul grande
#endif

#ifdef US_ACTIVE
constexpr uint8_t US_FL_TRIG_PIN = 26;
constexpr uint8_t US_FL_ECHO_PIN = 28;
constexpr uint8_t US_FR_TRIG_PIN = 31;
constexpr uint8_t US_FR_ECHO_PIN = 30;
constexpr uint8_t US_BL_TRIG_PIN = 52;
constexpr uint8_t US_BL_ECHO_PIN = 53;
constexpr uint8_t US_BR_TRIG_PIN = 50;
constexpr uint8_t US_BR_ECHO_PIN = 51;
#endif
