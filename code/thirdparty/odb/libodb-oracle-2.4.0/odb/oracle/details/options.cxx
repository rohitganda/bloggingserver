// This code was generated by CLI, a command line interface
// compiler for C++.
//

// Begin prologue.
//
//
// End prologue.

#include "options.hxx"

#include <map>
#include <set>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>
#include <cstring>
#include <fstream>

namespace odb
{
  namespace oracle
  {
    namespace details
    {
      namespace cli
      {
        // unknown_option
        //
        unknown_option::
        ~unknown_option () throw ()
        {
        }

        void unknown_option::
        print (::std::ostream& os) const
        {
          os << "unknown option '" << option ().c_str () << "'";
        }

        const char* unknown_option::
        what () const throw ()
        {
          return "unknown option";
        }

        // unknown_argument
        //
        unknown_argument::
        ~unknown_argument () throw ()
        {
        }

        void unknown_argument::
        print (::std::ostream& os) const
        {
          os << "unknown argument '" << argument ().c_str () << "'";
        }

        const char* unknown_argument::
        what () const throw ()
        {
          return "unknown argument";
        }

        // missing_value
        //
        missing_value::
        ~missing_value () throw ()
        {
        }

        void missing_value::
        print (::std::ostream& os) const
        {
          os << "missing value for option '" << option ().c_str () << "'";
        }

        const char* missing_value::
        what () const throw ()
        {
          return "missing option value";
        }

        // invalid_value
        //
        invalid_value::
        ~invalid_value () throw ()
        {
        }

        void invalid_value::
        print (::std::ostream& os) const
        {
          os << "invalid value '" << value ().c_str () << "' for option '"
             << option ().c_str () << "'";
        }

        const char* invalid_value::
        what () const throw ()
        {
          return "invalid option value";
        }

        // eos_reached
        //
        void eos_reached::
        print (::std::ostream& os) const
        {
          os << what ();
        }

        const char* eos_reached::
        what () const throw ()
        {
          return "end of argument stream reached";
        }

        // file_io_failure
        //
        file_io_failure::
        ~file_io_failure () throw ()
        {
        }

        void file_io_failure::
        print (::std::ostream& os) const
        {
          os << "unable to open file '" << file ().c_str () << "' or read failure";
        }

        const char* file_io_failure::
        what () const throw ()
        {
          return "unable to open file or read failure";
        }

        // unmatched_quote
        //
        unmatched_quote::
        ~unmatched_quote () throw ()
        {
        }

        void unmatched_quote::
        print (::std::ostream& os) const
        {
          os << "unmatched quote in argument '" << argument ().c_str () << "'";
        }

        const char* unmatched_quote::
        what () const throw ()
        {
          return "unmatched quote";
        }

        // scanner
        //
        scanner::
        ~scanner ()
        {
        }

        // argv_scanner
        //
        bool argv_scanner::
        more ()
        {
          return i_ < argc_;
        }

        const char* argv_scanner::
        peek ()
        {
          if (i_ < argc_)
            return argv_[i_];
          else
            throw eos_reached ();
        }

        const char* argv_scanner::
        next ()
        {
          if (i_ < argc_)
          {
            const char* r (argv_[i_]);

            if (erase_)
            {
              for (int i (i_ + 1); i < argc_; ++i)
                argv_[i - 1] = argv_[i];

              --argc_;
              argv_[argc_] = 0;
            }
            else
              ++i_;

            return r;
          }
          else
            throw eos_reached ();
        }

        void argv_scanner::
        skip ()
        {
          if (i_ < argc_)
            ++i_;
          else
            throw eos_reached ();
        }

        // argv_file_scanner
        //
        bool argv_file_scanner::
        more ()
        {
          if (!args_.empty ())
            return true;

          while (base::more ())
          {
            // See if the next argument is the file option.
            //
            const char* a (base::peek ());
            const option_info* oi;

            if (!skip_ && (oi = find (a)))
            {
              base::next ();

              if (!base::more ())
                throw missing_value (oi->option);

              if (oi->search_func != 0)
              {
                std::string f (oi->search_func (base::next (), oi->arg));

                if (!f.empty ())
                  load (f);
              }
              else
                load (base::next ());

              if (!args_.empty ())
                return true;
            }
            else
            {
              if (!skip_)
                skip_ = (std::strcmp (a, "--") == 0);

              return true;
            }
          }

          return false;
        }

        const char* argv_file_scanner::
        peek ()
        {
          if (!more ())
            throw eos_reached ();

          return args_.empty () ? base::peek () : args_.front ().c_str ();
        }

        const char* argv_file_scanner::
        next ()
        {
          if (!more ())
            throw eos_reached ();

          if (args_.empty ())
            return base::next ();
          else
          {
            hold_.swap (args_.front ());
            args_.pop_front ();
            return hold_.c_str ();
          }
        }

        void argv_file_scanner::
        skip ()
        {
          if (!more ())
            throw eos_reached ();

          if (args_.empty ())
            return base::skip ();
          else
            args_.pop_front ();
        }

        const argv_file_scanner::option_info* argv_file_scanner::
        find (const char* a) const
        {
          for (std::size_t i (0); i < options_count_; ++i)
            if (std::strcmp (a, options_[i].option) == 0)
              return &options_[i];

          return 0;
        }

        void argv_file_scanner::
        load (const std::string& file)
        {
          using namespace std;

          ifstream is (file.c_str ());

          if (!is.is_open ())
            throw file_io_failure (file);

          while (!is.eof ())
          {
            string line;
            getline (is, line);

            if (is.fail () && !is.eof ())
              throw file_io_failure (file);

            string::size_type n (line.size ());

            // Trim the line from leading and trailing whitespaces.
            //
            if (n != 0)
            {
              const char* f (line.c_str ());
              const char* l (f + n);

              const char* of (f);
              while (f < l && (*f == ' ' || *f == '\t' || *f == '\r'))
                ++f;

              --l;

              const char* ol (l);
              while (l > f && (*l == ' ' || *l == '\t' || *l == '\r'))
                --l;

              if (f != of || l != ol)
                line = f <= l ? string (f, l - f + 1) : string ();
            }

            // Ignore empty lines, those that start with #.
            //
            if (line.empty () || line[0] == '#')
              continue;

            string::size_type p (line.find (' '));

            if (p == string::npos)
            {
              if (!skip_)
                skip_ = (line == "--");

              args_.push_back (line);
            }
            else
            {
              string s1 (line, 0, p);

              // Skip leading whitespaces in the argument.
              //
              n = line.size ();
              for (++p; p < n; ++p)
              {
                char c (line[p]);

                if (c != ' ' && c != '\t' && c != '\r')
                  break;
              }

              string s2 (line, p);

              // If the string is wrapped in quotes, remove them.
              //
              n = s2.size ();
              char cf (s2[0]), cl (s2[n - 1]);

              if (cf == '"' || cf == '\'' || cl == '"' || cl == '\'')
              {
                if (n == 1 || cf != cl)
                  throw unmatched_quote (s2);

                s2 = string (s2, 1, n - 2);
              }

              const option_info* oi;
              if (!skip_ && (oi = find (s1.c_str ())))
              {
                if (s2.empty ())
                  throw missing_value (oi->option);

                if (oi->search_func != 0)
                {
                  std::string f (oi->search_func (s2.c_str (), oi->arg));

                  if (!f.empty ())
                    load (f);
                }
                else
                  load (s2);
              }
              else
              {
                args_.push_back (s1);
                args_.push_back (s2);
              }
            }
          }
        }

        template <typename X>
        struct parser
        {
          static void
          parse (X& x, bool& xs, scanner& s)
          {
            std::string o (s.next ());

            if (s.more ())
            {
              std::string v (s.next ());
              std::istringstream is (v);
              if (!(is >> x && is.eof ()))
                throw invalid_value (o, v);
            }
            else
              throw missing_value (o);

            xs = true;
          }
        };

        template <>
        struct parser<bool>
        {
          static void
          parse (bool& x, scanner& s)
          {
            s.next ();
            x = true;
          }
        };

        template <>
        struct parser<std::string>
        {
          static void
          parse (std::string& x, bool& xs, scanner& s)
          {
            const char* o (s.next ());

            if (s.more ())
              x = s.next ();
            else
              throw missing_value (o);

            xs = true;
          }
        };

        template <typename X>
        struct parser<std::vector<X> >
        {
          static void
          parse (std::vector<X>& c, bool& xs, scanner& s)
          {
            X x;
            bool dummy;
            parser<X>::parse (x, dummy, s);
            c.push_back (x);
            xs = true;
          }
        };

        template <typename X>
        struct parser<std::set<X> >
        {
          static void
          parse (std::set<X>& c, bool& xs, scanner& s)
          {
            X x;
            bool dummy;
            parser<X>::parse (x, dummy, s);
            c.insert (x);
            xs = true;
          }
        };

        template <typename K, typename V>
        struct parser<std::map<K, V> >
        {
          static void
          parse (std::map<K, V>& m, bool& xs, scanner& s)
          {
            std::string o (s.next ());

            if (s.more ())
            {
              std::string ov (s.next ());
              std::string::size_type p = ov.find ('=');

              if (p == std::string::npos)
              {
                K k = K ();

                if (!ov.empty ())
                {
                  std::istringstream ks (ov);

                  if (!(ks >> k && ks.eof ()))
                    throw invalid_value (o, ov);
                }

                m[k] = V ();
              }
              else
              {
                K k = K ();
                V v = V ();
                std::string kstr (ov, 0, p);
                std::string vstr (ov, p + 1);

                if (!kstr.empty ())
                {
                  std::istringstream ks (kstr);

                  if (!(ks >> k && ks.eof ()))
                    throw invalid_value (o, ov);
                }

                if (!vstr.empty ())
                {
                  std::istringstream vs (vstr);

                  if (!(vs >> v && vs.eof ()))
                    throw invalid_value (o, ov);
                }

                m[k] = v;
              }
            }
            else
              throw missing_value (o);

            xs = true;
          }
        };

        template <typename X, typename T, T X::*M>
        void
        thunk (X& x, scanner& s)
        {
          parser<T>::parse (x.*M, s);
        }

        template <typename X, typename T, T X::*M, bool X::*S>
        void
        thunk (X& x, scanner& s)
        {
          parser<T>::parse (x.*M, x.*S, s);
        }
      }
    }
  }
}

#include <map>
#include <cstring>

namespace odb
{
  namespace oracle
  {
    namespace details
    {
      // options
      //

      options::
      options ()
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
      }

      options::
      options (int& argc,
               char** argv,
               bool erase,
               ::odb::oracle::details::cli::unknown_mode opt,
               ::odb::oracle::details::cli::unknown_mode arg)
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
        ::odb::oracle::details::cli::argv_scanner s (argc, argv, erase);
        _parse (s, opt, arg);
      }

      options::
      options (int start,
               int& argc,
               char** argv,
               bool erase,
               ::odb::oracle::details::cli::unknown_mode opt,
               ::odb::oracle::details::cli::unknown_mode arg)
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
        ::odb::oracle::details::cli::argv_scanner s (start, argc, argv, erase);
        _parse (s, opt, arg);
      }

      options::
      options (int& argc,
               char** argv,
               int& end,
               bool erase,
               ::odb::oracle::details::cli::unknown_mode opt,
               ::odb::oracle::details::cli::unknown_mode arg)
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
        ::odb::oracle::details::cli::argv_scanner s (argc, argv, erase);
        _parse (s, opt, arg);
        end = s.end ();
      }

      options::
      options (int start,
               int& argc,
               char** argv,
               int& end,
               bool erase,
               ::odb::oracle::details::cli::unknown_mode opt,
               ::odb::oracle::details::cli::unknown_mode arg)
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
        ::odb::oracle::details::cli::argv_scanner s (start, argc, argv, erase);
        _parse (s, opt, arg);
        end = s.end ();
      }

      options::
      options (::odb::oracle::details::cli::scanner& s,
               ::odb::oracle::details::cli::unknown_mode opt,
               ::odb::oracle::details::cli::unknown_mode arg)
      : user_ (),
        user_specified_ (false),
        password_ (),
        password_specified_ (false),
        database_ (),
        database_specified_ (false),
        service_ (),
        service_specified_ (false),
        host_ (),
        host_specified_ (false),
        port_ (),
        port_specified_ (false),
        options_file_ (),
        options_file_specified_ (false)
      {
        _parse (s, opt, arg);
      }

      void options::
      print_usage (::std::ostream& os)
      {
        os << "--user <name>         Oracle database user." << ::std::endl;

        os << "--password <str>      Oracle database password." << ::std::endl;

        os << "--database <conn-id>  Oracle connect identifier." << ::std::endl;

        os << "--service <name>      Oracle service name." << ::std::endl;

        os << "--host <str>          Oracle database host name or address (localhost by" << ::std::endl
           << "                      default)." << ::std::endl;

        os << "--port <integer>      Oracle database port number." << ::std::endl;

        os << "--options-file <file> Read additional options from <file>. Each option" << ::std::endl
           << "                      appearing on a separate line optionally followed by space" << ::std::endl
           << "                      and an option value. Empty lines and lines starting with" << ::std::endl
           << "                      '#' are ignored." << ::std::endl;
      }

      typedef
      std::map<std::string, void (*) (options&, ::odb::oracle::details::cli::scanner&)>
      _cli_options_map;

      static _cli_options_map _cli_options_map_;

      struct _cli_options_map_init
      {
        _cli_options_map_init ()
        {
          _cli_options_map_["--user"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::user_,
            &options::user_specified_ >;
          _cli_options_map_["--password"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::password_,
            &options::password_specified_ >;
          _cli_options_map_["--database"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::database_,
            &options::database_specified_ >;
          _cli_options_map_["--service"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::service_,
            &options::service_specified_ >;
          _cli_options_map_["--host"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::host_,
            &options::host_specified_ >;
          _cli_options_map_["--port"] = 
          &::odb::oracle::details::cli::thunk< options, unsigned int, &options::port_,
            &options::port_specified_ >;
          _cli_options_map_["--options-file"] = 
          &::odb::oracle::details::cli::thunk< options, std::string, &options::options_file_,
            &options::options_file_specified_ >;
        }
      };

      static _cli_options_map_init _cli_options_map_init_;

      bool options::
      _parse (const char* o, ::odb::oracle::details::cli::scanner& s)
      {
        _cli_options_map::const_iterator i (_cli_options_map_.find (o));

        if (i != _cli_options_map_.end ())
        {
          (*(i->second)) (*this, s);
          return true;
        }

        return false;
      }

      void options::
      _parse (::odb::oracle::details::cli::scanner& s,
              ::odb::oracle::details::cli::unknown_mode opt_mode,
              ::odb::oracle::details::cli::unknown_mode arg_mode)
      {
        bool opt = true;

        while (s.more ())
        {
          const char* o = s.peek ();

          if (std::strcmp (o, "--") == 0)
          {
            s.skip ();
            opt = false;
            continue;
          }

          if (opt && _parse (o, s));
          else if (opt && std::strncmp (o, "-", 1) == 0 && o[1] != '\0')
          {
            switch (opt_mode)
            {
              case ::odb::oracle::details::cli::unknown_mode::skip:
              {
                s.skip ();
                continue;
              }
              case ::odb::oracle::details::cli::unknown_mode::stop:
              {
                break;
              }
              case ::odb::oracle::details::cli::unknown_mode::fail:
              {
                throw ::odb::oracle::details::cli::unknown_option (o);
              }
            }

            break;
          }
          else
          {
            switch (arg_mode)
            {
              case ::odb::oracle::details::cli::unknown_mode::skip:
              {
                s.skip ();
                continue;
              }
              case ::odb::oracle::details::cli::unknown_mode::stop:
              {
                break;
              }
              case ::odb::oracle::details::cli::unknown_mode::fail:
              {
                throw ::odb::oracle::details::cli::unknown_argument (o);
              }
            }

            break;
          }
        }
      }
    }
  }
}

// Begin epilogue.
//
//
// End epilogue.

