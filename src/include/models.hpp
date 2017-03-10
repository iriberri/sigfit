
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.14

#include <stan/model/model_header.hpp>

namespace model_sigfit_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

class model_sigfit : public prob_grad {
private:
    int C;
    int S;
    matrix_d signatures;
    vector<int> counts;
    vector_d alpha;
public:
    model_sigfit(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        typedef boost::ecuyer1988 rng_t;
        rng_t base_rng(0);  // 0 seed default
        ctor_body(context__, base_rng, pstream__);
    }

    template <class RNG>
    model_sigfit(stan::io::var_context& context__,
        RNG& base_rng__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, base_rng__, pstream__);
    }

    template <class RNG>
    void ctor_body(stan::io::var_context& context__,
                   RNG& base_rng__,
                   std::ostream* pstream__) {
        current_statement_begin__ = -1;

        static const char* function__ = "model_sigfit_namespace::model_sigfit";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        context__.validate_dims("data initialization", "C", "int", context__.to_vec());
        C = int(0);
        vals_i__ = context__.vals_i("C");
        pos__ = 0;
        C = vals_i__[pos__++];
        context__.validate_dims("data initialization", "S", "int", context__.to_vec());
        S = int(0);
        vals_i__ = context__.vals_i("S");
        pos__ = 0;
        S = vals_i__[pos__++];
        context__.validate_dims("data initialization", "signatures", "matrix_d", context__.to_vec(C,S));
        validate_non_negative_index("signatures", "C", C);
        validate_non_negative_index("signatures", "S", S);
        signatures = matrix_d(static_cast<Eigen::VectorXd::Index>(C),static_cast<Eigen::VectorXd::Index>(S));
        vals_r__ = context__.vals_r("signatures");
        pos__ = 0;
        size_t signatures_m_mat_lim__ = C;
        size_t signatures_n_mat_lim__ = S;
        for (size_t n_mat__ = 0; n_mat__ < signatures_n_mat_lim__; ++n_mat__) {
            for (size_t m_mat__ = 0; m_mat__ < signatures_m_mat_lim__; ++m_mat__) {
                signatures(m_mat__,n_mat__) = vals_r__[pos__++];
            }
        }
        context__.validate_dims("data initialization", "counts", "int", context__.to_vec(C));
        validate_non_negative_index("counts", "C", C);
        counts = std::vector<int>(C,int(0));
        vals_i__ = context__.vals_i("counts");
        pos__ = 0;
        size_t counts_limit_0__ = C;
        for (size_t i_0__ = 0; i_0__ < counts_limit_0__; ++i_0__) {
            counts[i_0__] = vals_i__[pos__++];
        }
        validate_non_negative_index("alpha", "S", S);
        alpha = vector_d(static_cast<Eigen::VectorXd::Index>(S));
        context__.validate_dims("data initialization", "alpha", "vector_d", context__.to_vec(S));
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0;
        size_t alpha_i_vec_lim__ = S;
        for (size_t i_vec__ = 0; i_vec__ < alpha_i_vec_lim__; ++i_vec__) {
            alpha[i_vec__] = vals_r__[pos__++];
        }

        // validate, data variables
        check_greater_or_equal(function__,"C",C,1);
        check_greater_or_equal(function__,"S",S,1);
        check_greater_or_equal(function__,"alpha",alpha,0);
        // initialize data variables

        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        num_params_r__ += (S - 1);
    }

    ~model_sigfit() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("exposures")))
            throw std::runtime_error("variable exposures missing");
        vals_r__ = context__.vals_r("exposures");
        pos__ = 0U;
        context__.validate_dims("initialization", "exposures", "vector_d", context__.to_vec(S));
        // generate_declaration exposures
        vector_d exposures(static_cast<Eigen::VectorXd::Index>(S));
        for (int j1__ = 0U; j1__ < S; ++j1__)
            exposures(j1__) = vals_r__[pos__++];
        try {
            writer__.simplex_unconstrain(exposures);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable exposures: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  exposures;
        (void) exposures;  // dummy to suppress unused var warning
        if (jacobian__)
            exposures = in__.simplex_constrain(S,lp__);
        else
            exposures = in__.simplex_constrain(S);


        // transformed parameters
        Eigen::Matrix<T__,Eigen::Dynamic,1>  probs(static_cast<Eigen::VectorXd::Index>(C));
        (void) probs;  // dummy to suppress unused var warning
        stan::math::initialize(probs, DUMMY_VAR__);
        stan::math::fill(probs,DUMMY_VAR__);


        try {
            stan::math::assign(probs, multiply(signatures,exposures));
            stan::math::assign(probs, divide(probs,sum(probs)));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters
        for (int i0__ = 0; i0__ < C; ++i0__) {
            if (stan::math::is_uninitialized(probs(i0__))) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: probs" << '[' << i0__ << ']';
                throw std::runtime_error(msg__.str());
            }
        }

        const char* function__ = "validate transformed params";
        (void) function__;  // dummy to suppress unused var warning
        stan::math::check_simplex(function__,"probs",probs);

        // model body
        try {

            lp_accum__.add(dirichlet_log<propto__>(exposures, alpha));
            lp_accum__.add(multinomial_log<propto__>(counts, probs));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("exposures");
        names__.push_back("probs");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(S);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(C);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_sigfit_namespace::write_array";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        vector_d exposures = in__.simplex_constrain(S);
        for (int k_0__ = 0; k_0__ < S; ++k_0__) {
            vars__.push_back(exposures[k_0__]);
        }

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        vector_d probs(static_cast<Eigen::VectorXd::Index>(C));
        (void) probs;  // dummy to suppress unused var warning
        stan::math::initialize(probs, std::numeric_limits<double>::quiet_NaN());
        stan::math::fill(probs,DUMMY_VAR__);


        try {
            stan::math::assign(probs, multiply(signatures,exposures));
            stan::math::assign(probs, divide(probs,sum(probs)));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters
        stan::math::check_simplex(function__,"probs",probs);

        // write transformed parameters
        for (int k_0__ = 0; k_0__ < C; ++k_0__) {
            vars__.push_back(probs[k_0__]);
        }

        if (!include_gqs__) return;
        // declare and define generated quantities


        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_sigfit";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= S; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "exposures" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= C; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "probs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= (S - 1); ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "exposures" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= (C - 1); ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "probs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

} // namespace




#endif
