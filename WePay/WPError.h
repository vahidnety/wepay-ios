//
//  WPError.h
//  WePay
//
//  Created by WePay on 10/2/13.
//  Copyright (c) 2013 WePay. All rights reserved.
//
#import <Foundation/Foundation.h>

/*
 The NSError domain of all errors returned by the WePay IOS DK.
 */
FOUNDATION_EXPORT NSString *const WePaySDKDomain;

/*
 The NSError domain of all errors surfaced by the WePay IOS SDK that
 were returned by the WePay API.
*/
FOUNDATION_EXPORT NSString *const WePayAPIDomain;

/*
 
 When you use the SDK's API call functions to make an API Call to WePay, you pass in an error callback function. 
 For example, to make the /credit_card/create API call, you pass in an error callback function to the 
 createCardWithDescriptor function in the WPCreditCard.m class. Before making the /credit_card/create API call to WePay, 
 the createCardWithDescriptor function validates the user input. If the input is invalid, it executes your error callback,
 passing it an NSError object as parameter describing the validation error. If the input is valid, it makes the API call 
 to WePay. If WePay returns an error, the SDK converts that error into an NSError object and executes your error callback
 function with that NSError object as parameter.
 
 There are three types of errors that can occur when using this SDK:
 
 In NSURLErrorDomain:
 
 * NSUrlErrorDomain errors (i.e. Network errors) These NSError objects are in the NSURLErrorDomain domain.
 These are the errors returned and generated by NSUrlConnection.
 
 In WePaySDKDomain domain:
 
 * Client-side validation Errors (i.e. invalid card, invalid cvv) These are validation errors generated 
 by the SDK code (the descriptor classes) itself when there are invalid user inputs. They are
 in the WePaySDKDomain.
 
 The userInfo dictionary WPErrorCategoryKey key value for these NSError objects correspond to the 
 descriptor class in which the error was generated.
 
 The following are the possible userInfo dictionary WPErrorCategoryKey key values for these NSError objects:
 
 - WPErrorCategoryCardValidation (validation error in the card descriptor class)
 - WPErrorCategoryUserValidation (validation error in the user descriptor class)
 - WPErrorCategoryAddressValidation (validation error in the address descriptor class)
 
 You can edit the WePay/Resources/en.lproj/WePay.strings file to change the error messages for these errors.
 
 In the WePayAPIDomain:
 
 * WePay API errors are errors returned by the WePay API server. WePay API errors are converted 
 into NSError objects with the same error code and description.
 
 The value of these errors' userInfo dictionary WPErrorCategoryKey key is the same as the "error" category
 parameter WePay API server sends back:
 
 - invalid_request
 - access_denied
 - invalid_scope
 - invalid_client
 - processing_error
 
 Please see https://www.wepay.com/developer/reference/errors for more information.
 
 All NSError objects have a localizable user facing error message that can be retrieved by calling [error localizedDescription].
 Please see 
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSError_Class/Reference/Reference.html
 for more information.
 
*/

FOUNDATION_EXPORT NSString *const WPErrorCategoryKey;

FOUNDATION_EXPORT NSString *const WPErrorCategoryNone;

/*
 These values may be returned for an error object's userinfo dictionary key WPErrorCategoryKey 
 from the call to createCardWithDescriptor or from any of the validation function calls.
 */
FOUNDATION_EXPORT NSString *const WPErrorCategoryValidation;
FOUNDATION_EXPORT NSString *const WPErrorCategoryCardValidation;
FOUNDATION_EXPORT NSString *const WPErrorCategoryUserValidation;
FOUNDATION_EXPORT NSString *const WPErrorCategoryAddressValidation;

/*
 Validation functions return NSError objects with these codes
 */
typedef NS_ENUM(NSInteger, WPErrorCode) {
    WPErrorUnknown = -10000,
    WPErrorInvalidCard,
    WPErrorInvalidCVV,
    WPErrorInvalidExpMonth,
    WPErrorInvalidExpYear,
    WPErrorInvalidUser,
    WPErrorInvalidUserName,
    WPErrorInvalidUserAddress,
    WPErrorInvalidUserEmail,
    WPErrorInvalidUserCity,
    WPErrorInvalidUserState,
    WPErrorInvalidUserCountry,
    WPErrorInvalidUserZip,
    WPErrorInvalidUserPostCode,
    WPErrorInvalidUserRegion
};

/*
 Maps to NSLocalizedDescriptionKey
 */
#define WPUnexpectedErrorMessage NSLocalizedStringFromTable(@"There was an unexpected error.", @"WePay", @"There was an unexpected error.");
#define WPNoDataReturnedErrorMessage NSLocalizedStringFromTable(@"There was no data returned.", @"WePay",  @"There was no data returned.");
#define WPUrlRequestFailedMessage NSLocalizedStringFromTable(@"The url request failed.", @"WePay",  @"The url request failed.");

@interface WPError : NSObject

// Maps a validation error code to an error description
+ (NSString *) validationErrorDescriptionForCode: (WPErrorCode) code;

@end
