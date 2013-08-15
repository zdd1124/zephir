
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string_type.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Test\Router\Route
 *
 * This class represents every route added to the router
 */
ZEPHIR_INIT_CLASS(Test_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Test\\Router, Route, router_route, test_router_route_method_entry, 0);

	zend_declare_property_null(test_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_compiledPattern"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_paths"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_methods"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_hostname"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_converters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(test_router_route_ce, SL("_beforeMatch"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Test\Router\Route constructor
 *
 * @param string pattern
 * @param array paths
 * @param array|string httpMethods
 */
PHP_METHOD(Test_Router_Route, __construct) {

	zval *pattern, *paths = NULL, *httpMethods = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern, &paths, &httpMethods);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}
	if (!httpMethods) {
		ZEPHIR_INIT_VAR(httpMethods);
	}


	//missing comment
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p2(_0, this_ptr, "reconfigure", pattern, paths);
	//missing comment

	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);

	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces placeholders from pattern returning a valid PCRE regular expression
 *
 * @param string pattern
 * @return string
 */
PHP_METHOD(Test_Router_Route, compilePattern) {

	zval *pattern, *compiledPattern, *idPattern, *patternCopy, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_23, *_24, *_25;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern);



	ZEPHIR_CPY_WRT(compiledPattern, pattern);

	//missing comment
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, ":", 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p2(_1, "memchr", pattern, _0);
	if (zend_is_true(_1)) {
		//missing comment

		ZEPHIR_INIT_VAR(idPattern);
		ZVAL_STRING(idPattern, "/([a-zA-Z0-9\\_\\-]+)", 1);

		//missing comment
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "/:module", 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p2(_3, "memchr", pattern, _2);
		if (zend_is_true(_3)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "/:module", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _4, idPattern, patternCopy);

		}
		//missing comment
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "/:controller", 1);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p2(_6, "memchr", pattern, _5);
		if (zend_is_true(_6)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_7);
			ZVAL_STRING(_7, "/:controller", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _7, idPattern, patternCopy);

		}
		//missing comment
		ZEPHIR_INIT_VAR(_8);
		ZVAL_STRING(_8, "/:namespace", 1);
		ZEPHIR_INIT_VAR(_9);
		zephir_call_func_p2(_9, "memchr", pattern, _8);
		if (zend_is_true(_9)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_10);
			ZVAL_STRING(_10, "/:namespace", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _10, idPattern, patternCopy);

		}
		//missing comment
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "/:action", 1);
		ZEPHIR_INIT_VAR(_12);
		zephir_call_func_p2(_12, "memchr", pattern, _11);
		if (zend_is_true(_12)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_13);
			ZVAL_STRING(_13, "/:action", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _13, idPattern, patternCopy);

		}
		//missing comment
		ZEPHIR_INIT_VAR(_14);
		ZVAL_STRING(_14, "/:params", 1);
		ZEPHIR_INIT_VAR(_15);
		zephir_call_func_p2(_15, "memchr", pattern, _14);
		if (zend_is_true(_15)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_16);
			ZVAL_STRING(_16, "/:params", 1);
			ZEPHIR_INIT_VAR(_17);
			ZVAL_STRING(_17, "(/.*)*", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _16, _17, patternCopy);

		}
		//missing comment
		ZEPHIR_INIT_VAR(_18);
		ZVAL_STRING(_18, "/:int", 1);
		ZEPHIR_INIT_VAR(_19);
		zephir_call_func_p2(_19, "memchr", pattern, _18);
		if (zend_is_true(_19)) {

			ZEPHIR_CPY_WRT(patternCopy, compiledPattern);

			ZEPHIR_INIT_VAR(_20);
			ZVAL_STRING(_20, "/:int", 1);
			ZEPHIR_INIT_VAR(_21);
			ZVAL_STRING(_21, "/([0-9]+)", 1);
			zephir_call_func_p3(compiledPattern, "str_replace", _20, _21, patternCopy);

		}
	}
	//missing comment
	ZEPHIR_INIT_VAR(_22);
	ZVAL_STRING(_22, "(", 1);
	ZEPHIR_INIT_VAR(_23);
	zephir_call_func_p2(_23, "memchr", compiledPattern, _22);
	if (zend_is_true(_23)) {

		RETURN_MM_NULL();

	}
	//missing comment
	ZEPHIR_INIT_VAR(_24);
	ZVAL_STRING(_24, "[", 1);
	ZEPHIR_INIT_VAR(_25);
	zephir_call_func_p2(_25, "memchr", compiledPattern, _24);
	if (zend_is_true(_25)) {

		RETURN_MM_NULL();

	}

	RETURN_CCTOR(compiledPattern);


}

/**
 * Set one or more HTTP methods that constraint the matching of the route
 *
 *<code>
 * $route->via('GET');
 * $route->via(array('GET', 'POST'));
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, via) {

	zval *httpMethods;

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Extracts parameters from a string
 */
PHP_METHOD(Test_Router_Route, extractNamedParams) {

	zval *pattern_param = NULL;
	zephir_str *pattern;

	zephir_fetch_params(0, 1, 0, &pattern_param);



	//missing comment
	//missing comment

}

/**
 * Reconfigure the route adding a new pattern and a set of paths
 *
 * @param string pattern
 * @param array paths
 */
PHP_METHOD(Test_Router_Route, reConfigure) {

	zval *pattern, *paths = NULL, *moduleName = NULL, *controllerName = NULL, *actionName = NULL, *parts, *numberParts, *routePaths = NULL, *realClassName, *namespaceName, *lowerName, *pcrePattern, *compiledPattern, *extracted, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &paths);

	if (!paths) {
		ZEPHIR_INIT_VAR(paths);
	}


	if (Z_TYPE_P(pattern) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The pattern must be string");
		return;
	}
	if (Z_TYPE_P(paths) != IS_NULL) {
		if (Z_TYPE_P(paths) == IS_STRING) {

			ZEPHIR_INIT_VAR(moduleName);
			ZVAL_NULL(moduleName);

			ZEPHIR_INIT_VAR(controllerName);
			ZVAL_NULL(controllerName);

			ZEPHIR_INIT_VAR(actionName);
			ZVAL_NULL(actionName);

			//missing comment
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "::", 1);
			zephir_call_func_p2(parts, "explode", _0, paths);

			ZEPHIR_INIT_VAR(numberParts);
			ZVAL_LONG(numberParts, zephir_fast_count_ev(parts));

			//missing comment
			do {
				if (ZEPHIR_IS_LONG(numberParts, 3)) {
					ZEPHIR_OBS_NVAR(moduleName);
					zephir_array_fetch_long(&moduleName, parts, 0, PH_NOISY);

					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 1, PH_NOISY);

					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 2, PH_NOISY);

					break;
				}
				if (ZEPHIR_IS_LONG(numberParts, 2)) {
					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 0, PH_NOISY);

					ZEPHIR_OBS_NVAR(actionName);
					zephir_array_fetch_long(&actionName, parts, 1, PH_NOISY);

					break;
				}
				if (ZEPHIR_IS_LONG(numberParts, 1)) {
					ZEPHIR_OBS_NVAR(controllerName);
					zephir_array_fetch_long(&controllerName, parts, 0, PH_NOISY);

					break;
				}
			} while(0); 

			ZEPHIR_INIT_VAR(routePaths);
			array_init(routePaths);

			//missing comment
			if (Z_TYPE_P(moduleName) != IS_NULL) {

				zephir_array_update_string(&routePaths, SL("module"), &moduleName, PH_COPY | PH_SEPARATE);

			}
			//missing comment
			if (Z_TYPE_P(controllerName) != IS_NULL) {
				//missing comment
				ZEPHIR_INIT_VAR(_1);
				ZVAL_STRING(_1, "\\\\", 1);
				ZEPHIR_INIT_VAR(_2);
				zephir_call_func_p2(_2, "memchr", controllerName, _1);
				if (zend_is_true(_2)) {
					//missing comment
					zephir_call_func_p1(realClassName, "get_class_ns", controllerName);

					//missing comment
					zephir_call_func_p1(namespaceName, "get_ns_class", controllerName);

					//missing comment
					if (zend_is_true(namespaceName)) {

						zephir_array_update_string(&routePaths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);

					}
				} else {

					ZEPHIR_CPY_WRT(realClassName, controllerName);

				}
				//missing comment
				zephir_call_func_p1(lowerName, "uncamelize", realClassName);

				//missing comment

				zephir_array_update_string(&routePaths, SL("controller"), &lowerName, PH_COPY | PH_SEPARATE);

			}
			//missing comment
			if (Z_TYPE_P(actionName) != IS_NULL) {

				zephir_array_update_string(&routePaths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);

			}
		} else {

			ZEPHIR_CPY_WRT(routePaths, paths);

		}
	} else {

		ZEPHIR_INIT_NVAR(routePaths);
		array_init(routePaths);

	}
	if (Z_TYPE_P(routePaths) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(test_router_exception_ce, "The route contains invalid paths");
		return;
	}
	//missing comment
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "#", 1);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "starts_with", pattern, _3);
	if (!(zend_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "{", 1);
		ZEPHIR_INIT_VAR(_6);
		zephir_call_func_p2(_6, "memchr", pattern, _5);
		if (zend_is_true(_6)) {
			//missing comment
			ZEPHIR_INIT_VAR(extracted);
			zephir_call_method_p1(extracted, this_ptr, "extractnamedparams", pattern);

			ZEPHIR_OBS_VAR(pcrePattern);
			zephir_array_fetch_long(&pcrePattern, extracted, 0, PH_NOISY);

			ZEPHIR_OBS_NVAR(routePaths);
			zephir_array_fetch_long(&routePaths, extracted, 1, PH_NOISY);

		} else {

			ZEPHIR_CPY_WRT(pcrePattern, pattern);

		}
		//missing comment
		ZEPHIR_INIT_VAR(compiledPattern);
		zephir_call_method_p1(compiledPattern, this_ptr, "compilepattern", pcrePattern);

	} else {

		ZEPHIR_CPY_WRT(compiledPattern, pattern);

	}
	//missing comment

	zephir_update_property_zval(this_ptr, SL("_pattern"), pattern TSRMLS_CC);

	//missing comment

	zephir_update_property_zval(this_ptr, SL("_compiledPattern"), compiledPattern TSRMLS_CC);

	//missing comment

	zephir_update_property_zval(this_ptr, SL("_paths"), routePaths TSRMLS_CC);

	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the route's name
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getName) {

	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Sets the route's name
 *
 *<code>
 * $router->add('/about', array(
 *     'controller' => 'about'
 * ))->setName('about');
 *</code>
 *
 * @param string name
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, setName) {

	zval *name;

	zephir_fetch_params(0, 1, 0, &name);



	zephir_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treaded as not matched
 *
 * @param callback callback
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, beforeMatch) {

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("_beforeMatch"), callback TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Returns the 'before match' callback if any
 *
 * @return mixed
 */
PHP_METHOD(Test_Router_Route, getBeforeMatch) {

	RETURN_MEMBER(this_ptr, "_beforeMatch");

}

/**
 * Returns the route's id
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getRouteId) {

	RETURN_MEMBER(this_ptr, "_id");

}

/**
 * Returns the route's pattern
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getPattern) {

	RETURN_MEMBER(this_ptr, "_pattern");

}

/**
 * Returns the route's compiled pattern
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getCompiledPattern) {

	RETURN_MEMBER(this_ptr, "_compiledPattern");

}

/**
 * Returns the paths
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getPaths) {

	RETURN_MEMBER(this_ptr, "_paths");

}

/**
 * Returns the paths using positions as keys and names as values
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getReversedPaths) {

	HashTable *_2;
	HashPosition _1;
	zval *reversed, *path = NULL, *position = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(reversed);
	array_init(reversed);

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, this_ptr, SL("_paths"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HKEY(path, _2, _1);
		ZEPHIR_GET_HVALUE(position, _3);

		zephir_array_update_zval(&reversed, position, &path, PH_COPY | PH_SEPARATE);

	}

	RETURN_CCTOR(reversed);


}

/**
 * Sets a set of HTTP methods that constraint the matching of the route (alias of via)
 *
 *<code>
 * $route->setHttpMethods('GET');
 * $route->setHttpMethods(array('GET', 'POST'));
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, setHttpMethods) {

	zval *httpMethods;

	zephir_fetch_params(0, 1, 0, &httpMethods);



	zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Returns the HTTP methods that constraint matching the route
 *
 * @return string|array
 */
PHP_METHOD(Test_Router_Route, getHttpMethods) {

	RETURN_MEMBER(this_ptr, "_methods");

}

/**
 * Sets a hostname restriction to the route
 *
 *<code>
 * $route->setHostname('localhost');
 *</code>
 *
 * @param string|array httpMethods
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, setHostname) {

	zval *hostname;

	zephir_fetch_params(0, 1, 0, &hostname);



	zephir_update_property_zval(this_ptr, SL("_hostname"), hostname TSRMLS_CC);

	RETURN_THISW();


}

/**
 * Returns the hostname restriction if any
 *
 * @return string
 */
PHP_METHOD(Test_Router_Route, getHostname) {

	RETURN_MEMBER(this_ptr, "_hostname");

}

/**
 * Adds a converter to perform an additional transformation for certain parameter
 *
 * @param string name
 * @param callable converter
 * @return Test\Router\Route
 */
PHP_METHOD(Test_Router_Route, convert) {

	zval *name, *converter;

	zephir_fetch_params(0, 2, 0, &name, &converter);



	//missing object-property-array-index

	RETURN_THISW();


}

/**
 * Returns the router converter
 *
 * @return array
 */
PHP_METHOD(Test_Router_Route, getConverters) {

	RETURN_MEMBER(this_ptr, "_converters");

}

