#ifndef __CORELIB_CONFIG_H__
#define __CORELIB_CONFIG_H__ 1

/**
 * Log level messages are printed as strings.
 * @note Currently only supports Tagged strings.
 *
 * Todo: Add support for
 * 0 - No strings (e.g. Hello world)
 * Todo: Add support for
 * 1 - Char (e.g. D: 'Hello world')
 * Todo: Add support for
 * 2 - String (e.g. Debug: "Hello world")
 * Todo: Add support for
 * 3 - Short tags (e.g. [D] Hello world)
 * 4 - Tagged string (e.g. [ DEBUG ] Hello world)
 * Todo: Add support for
 * 5 - Padded tags e.g. [  DEBUG   ] Hello, world!
 *                      [   WARN   ] Hello, world!
 *                      [   INFO   ] Hello, world!
 *                      [  ERROR   ] Hello, world!
 *                      [ CRITICAL ] Hello, world!
 *                      [  FATAL   ] Hello, world!
 */
#define CORELIB_LOG_LEVEL_STRING_TYPE 4

/**
 * Visualizer to which for instrumentor should format the output.
 * 0 - Chrome
 * Todo: Add support for
 * 1 - Spall
 */
#define CORELIB_INSTRUMENTOR_VISUALIZER 0

#endif // __CORELIB_CONFIG_H__
