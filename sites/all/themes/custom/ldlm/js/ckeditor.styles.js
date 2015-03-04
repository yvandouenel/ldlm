/*
Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet( 'drupal',
    [                 
            { name : 'Fond bleu marine'	, element : 'div', attributes : { 'class' : 'bg-deep-blue' } },
            { name : 'Signature'	, element : 'div', attributes : { 'class' : 'signature' } },
            { name : 'Lien fleche bleue'	, element : 'a', attributes : { 'class' : 'link-blue-arrow' } },
            { name : 'Image droite'	, element : 'img', attributes : { 'class' : 'droite' } },
            { name : 'Image gauche'	, element : 'img', attributes : { 'class' : 'gauche' } }
            
    ]);
}