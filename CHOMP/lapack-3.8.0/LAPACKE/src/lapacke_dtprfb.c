/*****************************************************************************
  Copyright (c) 2014, Intel Corp.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************
* Contents: Native high-level C interface to LAPACK function dtprfb
* Author: Intel Corporation
* Generated June 2016
*****************************************************************************/

#include "lapacke_utils.h"

lapack_int LAPACKE_dtprfb( int matrix_layout, char side, char trans, char direct,
                           char storev, lapack_int m, lapack_int n,
                           lapack_int k, lapack_int l, const double* v,
                           lapack_int ldv, const double* t, lapack_int ldt,
                           double* a, lapack_int lda, double* b, lapack_int ldb )
{
    lapack_int ncols_v, nrows_v;
    lapack_int info = 0;
    lapack_int ldwork;
    lapack_int work_size;
    double* work = NULL;
    if( matrix_layout != LAPACK_COL_MAJOR && matrix_layout != LAPACK_ROW_MAJOR ) {
        LAPACKE_xerbla( "LAPACKE_dtprfb", -1 );
        return -1;
    }
#ifndef LAPACK_DISABLE_NAN_CHECK
    if( LAPACKE_get_nancheck() ) {
        /* Optionally check input matrices for NaNs */
        if( LAPACKE_lsame( storev, 'C' ) ) {
            ncols_v = k;
            nrows_v = LAPACKE_lsame( side, 'L' ) ? m :
                                 ( LAPACKE_lsame( side, 'R' ) ? n : 0 );
        } else if( LAPACKE_lsame( storev, 'R' ) ) {
            ncols_v = LAPACKE_lsame( side, 'L' ) ? m :
                                 ( LAPACKE_lsame( side, 'R' ) ? n : 0 );
            nrows_v = k;
        } else {
            ncols_v = 0;
            nrows_v = 0;
        }
        if( LAPACKE_dge_nancheck( matrix_layout, k, m, a, lda ) ) {
            return -14;
        }
        if( LAPACKE_dge_nancheck( matrix_layout, m, n, b, ldb ) ) {
            return -16;
        }
        if( LAPACKE_dge_nancheck( matrix_layout, k, k, t, ldt ) ) {
            return -12;
        }
        if( LAPACKE_dge_nancheck( matrix_layout, nrows_v, ncols_v, v, ldv ) ) {
            return -10;
        }
    }
#endif
    if (side=='l' ||  side=='L') {
       ldwork = k;
       work_size = MAX(1,ldwork) * MAX(1,n);
       }
    else {
       ldwork = m;
       work_size = MAX(1,ldwork) * MAX(1,k);
       }
    /* Allocate memory for working array(s) */
    work = (double*)
    LAPACKE_malloc( sizeof(double) * work_size );
    if( work == NULL ) {
        info = LAPACK_WORK_MEMORY_ERROR;
        goto exit_level_0;
    }
    /* Call middle-level interface */
    info = LAPACKE_dtprfb_work( matrix_layout, side, trans, direct, storev, m, n,
                                k, l, v, ldv, t, ldt, a, lda, b, ldb, work,
                                ldwork );
    /* Release memory and exit */
    LAPACKE_free( work );
exit_level_0:
    if( info == LAPACK_WORK_MEMORY_ERROR ) {
        LAPACKE_xerbla( "LAPACKE_dtprfb", info );
    }
    return info;
}