// 325483444 gidirabi111@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;
using namespace std;

int return_code = -1;

struct ReporterCounter : public ConsoleReporter
{
    ReporterCounter(const ContextOptions &input_options)
        : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats &run_stats) override
    {
        if (run_stats.numAssertsFailed == 0)
        {
            cout << "All tests passed!" << endl;
        }
        return_code = 0;
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

int main(int argc, char **argv)
{
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}