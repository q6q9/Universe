<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<!-- saved from url=(0056)https://www.boost.org/doc/libs/1_63_0/boost/function.hpp -->
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en" class=" qlpyzfdkqi idc0_330"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  <meta name="viewport" content="width=device-width,initial-scale=1.0">

<title>boost/function.hpp - 1.63.0</title>  <link rel="icon" href="https://www.boost.org/favicon.ico" type="image/ico">
  <link rel="stylesheet" type="text/css" href="./boost_function_files/section-doc.css">
  <!--[if IE 7]> <style type="text/css"> body { behavior: url(/style-v2/csshover3.htc); } </style> <![endif]-->

</head>

<body>
  <div id="heading">
    <div class="heading-inner">
  <div class="heading-placard"></div>

  <h1 class="heading-title">
  <a href="https://www.boost.org/">
  <img src="./boost_function_files/space.png" alt="Boost C++ Libraries" class="heading-logo">
  <span class="heading-boost">Boost</span>
  <span class="heading-cpplibraries">C++ Libraries</span>
  </a></h1>

  <p class="heading-quote">
  <q>...one of the most highly
  regarded and expertly designed C++ library projects in the
  world.</q> <span class="heading-attribution">— <a href="http://www.gotw.ca/" class="external">Herb Sutter</a> and <a href="http://en.wikipedia.org/wiki/Andrei_Alexandrescu" class="external">Andrei
  Alexandrescu</a>, <a href="http://safari.awprofessional.com/?XmlId=0321113586" class="external">C++
  Coding Standards</a></span></p>
</div>
  </div>
  <div class="boost-common-header-notice"><a class="boost-common-header-inner" href="https://www.boost.org/doc/libs/release/boost/function.hpp">This is the documentation for an old version of Boost.
                Click here to view this page for the latest version.</a></div>

  <div id="body">
    <div id="body-inner">
      <div id="content">
        <div class="section" id="docs">
          <div class="section-0">
            <div class="section-body">
              <h3>boost/function.hpp</h3>
<pre>// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  <a href="http://www.boost.org/LICENSE_1_0.txt">http://www.boost.org/LICENSE_1_0.txt</a>)

// For more information, see <a href="https://www.boost.org/doc/libs/1_63_0/libs/function">http://www.boost.org/libs/function</a>

// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

#include &lt;functional&gt; // unary_function, binary_function

#include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/preprocessor/iterate.hpp">boost/preprocessor/iterate.hpp</a>&gt;
#include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/detail/workaround.hpp">boost/detail/workaround.hpp</a>&gt;

#ifndef BOOST_FUNCTION_MAX_ARGS
#  define BOOST_FUNCTION_MAX_ARGS 10
#endif // BOOST_FUNCTION_MAX_ARGS

// Include the prologue here so that the use of file-level iteration
// in anything that may be included by function_template.hpp doesn't break
#include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/detail/prologue.hpp">boost/function/detail/prologue.hpp</a>&gt;

// Older Visual Age C++ version do not handle the file iteration well
#if BOOST_WORKAROUND(__IBMCPP__, &gt;= 500) &amp;&amp; BOOST_WORKAROUND(__IBMCPP__, &lt; 800)
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 0
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function0.hpp">boost/function/function0.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 1
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function1.hpp">boost/function/function1.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 2
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function2.hpp">boost/function/function2.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 3
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function3.hpp">boost/function/function3.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 4
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function4.hpp">boost/function/function4.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 5
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function5.hpp">boost/function/function5.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 6
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function6.hpp">boost/function/function6.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 7
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function7.hpp">boost/function/function7.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 8
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function8.hpp">boost/function/function8.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 9
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function9.hpp">boost/function/function9.hpp</a>&gt;
#  endif
#  if BOOST_FUNCTION_MAX_ARGS &gt;= 10
#    include &lt;<a href="https://www.boost.org/doc/libs/1_63_0/boost/function/function10.hpp">boost/function/function10.hpp</a>&gt;
#  endif
#else
// What is the '3' for?
#  define BOOST_PP_ITERATION_PARAMS_1 (3,(0,BOOST_FUNCTION_MAX_ARGS,&lt;boost/function/detail/function_iterate.hpp&gt;))
#  include BOOST_PP_ITERATE()
#  undef BOOST_PP_ITERATION_PARAMS_1
#endif
</pre>
            </div>
          </div>
        </div>
      </div>

      <div class="clear"></div>
    </div>
  </div>

  <div id="footer">
    <div id="footer-left">
      <div id="revised">
        <p>Revised $Date$</p>
      </div>

      <div id="copyright">
        <p>Copyright Beman Dawes, David Abrahams, 1998-2005.</p>

        <p>Copyright Rene Rivera 2004-2008.</p>
      </div>  <div id="license">
    <p>Distributed under the <a href="https://www.boost.org/LICENSE_1_0.txt" class="internal">Boost Software License, Version 1.0</a>.</p>
  </div>
    </div>

    <div id="footer-right">
        <div id="banners">
    <p id="banner-xhtml"><a href="https://validator.w3.org/check?uri=referer" class="external">XHTML 1.0</a></p>

    <p id="banner-css"><a href="https://jigsaw.w3.org/css-validator/check/referer" class="external">CSS</a></p>

    <p id="banner-osi"><a href="https://opensource.org/docs/definition.php" class="external">OSI
    Certified</a></p>
  </div>
    </div>

    <div class="clear"></div>
  </div>


<div class="mallbery-caa" style="z-index: 2147483647 !important; text-transform: none !important; position: fixed;"></div><div class="mallbery-caa" style="z-index: 2147483647 !important; text-transform: none !important; position: fixed;"></div><div at-magnifier-wrapper=""><div class="at-theme-light"><div class="at-base notranslate" translate="no"><div class="Z1-AJ" style="top: 0px; left: 0px;"></div></div></div></div></body></html>